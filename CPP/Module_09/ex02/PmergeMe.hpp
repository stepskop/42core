#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <set>
# include <ctime>
# include <cstdlib>

class PmergeMe
{
    private:
        template <typename Container>
        static void fordJohnsonMergeInsertionSort(Container &input);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);

		PmergeMe &operator = (const PmergeMe &src);

		static void	sort(int argc, char **argv, bool allowDuplicates = false);
};

#endif
