#include "PmergeMe.hpp"

template <typename Container>
bool isSorted(const Container &c) {
    if (c.size() < 2) return true;
    for (size_t i = 1; i < c.size(); i++)
        if (c[i - 1] > c[i]) return false;
    return true;
}

template <typename ForwardIt1, typename ForwardIt2>
ForwardIt2 swapRanges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2) {
    while (first1 != last1) {
        std::swap(*first1, *first2);
        ++first1;
        ++first2;
    }
    return first2;
}

// No upper_bound in C++98 :(, creating my own.
std::vector<int>::iterator upper_bound(std::vector<int>::iterator first, std::vector<int>::iterator last, int value)
{
    while (first != last)
    {
        std::vector<int>::iterator mid = first;
        std::advance(mid, std::distance(first, last) / 2);

        if (value < *mid)
            last = mid;
        else
            first = mid + 1;
    }
    return first;
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &src)
{
    (void)src; // No member variables to copy
	return *this;
}

PmergeMe::~PmergeMe(void)
{
}


template <typename T>
struct MustBeInt;

// only define it for int
template <>
struct MustBeInt<int> {
    typedef int type;
};

template <typename Container>
void PmergeMe::fordJohnsonMergeInsertionSort(Container &input) {
    // Compile-time check for int type. Hacky as it is not supported by C++98.
    // It is the only way to enforce the type requirement without using C++11 or C++20 features :(.
    typedef typename MustBeInt<typename Container::value_type>::type check;
    (void)sizeof(check); // To avoid unused typedef warning :(

    size_t groupSize = 1;
    size_t maxGroupSize = groupSize;

    // 1. Divide & Swap
    while (groupSize * 2 <= input.size()) {
        maxGroupSize = groupSize;
        size_t numPairs = input.size() / (groupSize * 2);

        for (size_t i = 0; i < numPairs; i++) {
            size_t firstStart = i * 2 * groupSize;
            size_t secondStart = firstStart + groupSize;

            // Compare last elements of each group and swap if first > second
            if (input[firstStart + groupSize - 1] > input[secondStart + groupSize - 1]) {
                swapRanges(
                    input.begin() + firstStart,
                    input.begin() + firstStart + groupSize,
                    input.begin() + secondStart
                );
            }
        }
        groupSize *= 2;
    }

    // 2. Initalize & Insert
    for (size_t groupSize = maxGroupSize; groupSize >= 1; groupSize /= 2) {
        size_t numGroup = input.size() / groupSize;
        size_t numPairs = input.size() / (groupSize * 2); // Number of pairs of groups
        bool hasOdd = (numGroup % 2 == 1); // If there is odd amount of groups

        // Initialize MAIN
        std::vector<typename Container::iterator> main; // Vector of iterators pointing at start of the group

        main.push_back(input.begin()); // Push b1
        main.push_back(input.begin() + groupSize); // Push a1
        // Push rest of the a's (a2, a3,...)
        size_t i = 1;
        while (i < numPairs) {
            main.push_back(input.begin() + (i * 2 + 1) * groupSize);
            i++;
        }

        // Initialize PEND
        std::vector<typename Container::iterator> pend; // Vector of iterators pointing at start of the group
        // Positions of aX elements in main for bounded bX elements in pend
        // If pend[0] is b2, then bounds[0] is index of a2 in main
        std::vector<size_t> bounds;

        // Push rest of the b's (b2, b3,...) to pend
        size_t j = 1;
        while (j < numPairs) {
            pend.push_back(input.begin() + (j * 2) * groupSize);
            bounds.push_back(j + 1); // aX is at main[i+1] initially
            j++;
        }

        if (hasOdd) {
            pend.push_back(input.begin() + numPairs * 2 * groupSize); // Push the odd b element
            bounds.push_back(main.size()); // Indicates that the bound element (a) doesnt exist in main
        }

        if (pend.empty())
            continue;

        // Create insertion order using Jacobsthal numbers
        std::vector<int> order;

        size_t prev_j = 1;
        size_t curr_j = 3;

        while (prev_j <= pend.size()) {
            size_t start = std::min(pend.size(), curr_j - 1) - 1;
            size_t end = prev_j - 1;

            for (int i = (int)start; i >= (int)end; i--) {
                order.push_back(i);
            }

            // Get next Jacobsthal number
            size_t next_j = curr_j + 2 * prev_j;
            prev_j = curr_j;
            curr_j = next_j;
        }

        // Insert PEND elements to MAIN
        for (size_t i = 0; i < order.size(); i++) {
            size_t pendIndex = order[i]; // Index of inserted b element
            size_t boundIndex = bounds[pendIndex]; // Index of related a element in main (the upper bound for the search)

            // Number that we are going to use when comparing during insertion - last element of the bX group
            int key = *(pend[pendIndex] + groupSize - 1);

            // Actual numbers (last elements of groups) from 'main' that we will compare the 'key' with. Needed for upper_bound()
            // This feels like a redundant step, but it is necessary since main is list of iterators not numbers.
            std::vector<int> main_keys;
            for (size_t i = 0; i < boundIndex; i++) {
                int num = *(main[i] + groupSize - 1);
                main_keys.push_back(num);
            }

            // Search for the position in the range of main_keys
            std::vector<int>::iterator pos = upper_bound(main_keys.begin(), main_keys.end(), key);

            // Get the index of main where we want to insert the b element
            // This only works because 'main' and 'a_keys' are parallel
            //
            // main:   [*b1,      *a1,      *a2,      *a3     ]
            // a_keys: [b1[last], a1[last], a2[last], a3[last]]
            size_t insertAt = pos - main_keys.begin();

            main.insert(main.begin() + insertAt, pend[pendIndex]);

            // Update bound indexes after inserting
            // All positions (indexes) in 'bounds' that are after the newly inserted element needs to be increased by 1,
            // since the elements in 'main' that they are pointing to were shifted to the right by the insertion.
            for (size_t j = i + 1; j < order.size(); j++) {
                size_t targetBoundIndex = order[j];
                if (bounds[targetBoundIndex] >= insertAt) {
                    bounds[targetBoundIndex]++;
                }
            }
        }

        // Copy the MAIN back to the original
        std::vector<int> tmp;
        for (size_t i = 0; i < main.size(); i++) {
            for (size_t j = 0; j < groupSize; j++) {
                tmp.push_back(*(main[i] + j));
            }
        }

        // Copy the leftovers (elements that couldnt form a group)
        size_t inGroups = main.size() * groupSize; // Total number of numbers that could form the group
        // input.size() - inGroups is what is left outside of the groups
        // We need to add these remaining numbers to the end and sort them in next round
        for (size_t i = inGroups; i < input.size(); i++) {
            tmp.push_back(input[i]);
        }

        std::copy(tmp.begin(), tmp.end(), input.begin());
    }
}

void PmergeMe::sort(int argc, char **argv, bool allowDuplicates)
{
    std::vector<int>	vec;
    std::deque<int>	    deq;
    std::set<int>		seen;

    for (int i = 1; i < argc; i++)
    {
        int num = std::atoi(argv[i]);

        if (num < 0)
        {
            std::cerr << "Error: invalid input (must be positive)." << std::endl;
            return;
        }

        if (!allowDuplicates && seen.find(num) != seen.end())
        {
            std::cerr << "Error: duplicate value " << num << "." << std::endl;
            return;
        }
        seen.insert(num);

        vec.push_back(num);
        deq.push_back(num);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::clock_t vecStart = std::clock();
    fordJohnsonMergeInsertionSort(vec);
    std::clock_t vecEnd = std::clock();

    std::clock_t deqStart = std::clock();
    fordJohnsonMergeInsertionSort(deq);
    std::clock_t deqEnd = std::clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    double vecUs = vecEnd - vecStart;
    double deqUs = deqEnd - deqStart;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecUs << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << deqUs << " us" << std::endl;

    if (!isSorted(vec))
        std::cerr << "Error: std::vector not sorted." << std::endl;
    if (!isSorted(deq))
        std::cerr << "Error: std::deque not sorted." << std::endl;
}
