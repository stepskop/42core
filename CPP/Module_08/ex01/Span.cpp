#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

Span::Span(): _size(0) {}

Span::Span(unsigned int n): _size(n) {}

Span::Span(const Span &src) {
    *this = src;
}

Span &Span::operator=(const Span &src) {
    if (this != &src) {
        this->_size = src._size;
        this->_nums = src._nums;
    }
    return (*this);
}

Span::~Span() {}


void    Span::addNumber(int n) {
    if (this->_nums.size() + 1 > this->_size)
        throw Span::TooManyItemsException();
    this->_nums.push_back(n);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (this->_nums.size() + std::distance(begin, end) > this->_size)
        throw Span::TooManyItemsException();
    this->_nums.insert(this->_nums.end(), begin, end);
}

int Span::shortestSpan() const {
    if (this->_nums.size() <= 1)
        throw Span::NotEnoughItemsException();

    std::vector<int> sorted = this->_nums;
    std::sort(sorted.begin(), sorted.end());

    int res = *(sorted.begin() + 1) - *(sorted.begin());

    for (std::vector<int>::iterator i = sorted.begin() + 1; i != sorted.end(); i++) {
        int curr = *(i) - *(i - 1);
        if (res > curr)
            res = curr;
    }

    return res;
}

int Span::longestSpan() const {
    if (this->_nums.size() <= 1)
        throw Span::NotEnoughItemsException();

    std::vector<int> sorted = this->_nums;
    std::sort(sorted.begin(), sorted.end());

    int res = *(sorted.end() - 1) - *(sorted.begin());

    return res;
}

const char  *Span::TooManyItemsException::what() const throw() {
    return "Too many items in the span";
}

const char  *Span::NotEnoughItemsException::what() const throw() {
    return "Not enough items to calculate span";
}
