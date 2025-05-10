#include "Span.hpp"

template <typename U, size_t N>
std::vector<U> toVector(U (&arr)[N]) {
	return std::vector<U>(arr, arr + N);
}

int main() {
    Span sp(5);

    sp.addNumber(6);

    try {
        std::cout << sp.shortestSpan() << std::endl; // Should throw not enough items
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;    // 2
    std::cout << sp.longestSpan() << std::endl;     // 14

    try {
        sp.addNumber(78); // Should throw - size to low
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span tooShort(6);
    Span enoughLong(7);

    int arr[] = { 3, 52, -1, 14, 5, 32, 9 };
    std::vector<int> vec = toVector(arr);

    try {
        tooShort.addNumber(vec.begin(), vec.end()); // Should throw - size too low
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    enoughLong.addNumber(vec.begin(), vec.end());

    std::cout << enoughLong.shortestSpan() << std::endl;    // 2
    std::cout << enoughLong.longestSpan() << std::endl;     // 53
}
