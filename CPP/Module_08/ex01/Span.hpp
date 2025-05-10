#include <exception>
#include <iostream>
#include <vector>

class Span {
private:
    unsigned int        _size;
    std::vector<int>    _nums;
public:
    Span();
    Span(unsigned int size);
    Span(const Span &src);
    ~Span();

    Span    &operator = (const Span &src);

    void    addNumber(int n);
	void 	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int		shortestSpan() const;
	int		longestSpan() const;

	class NotEnoughItemsException : public std::exception {
	    public:
            virtual const char *what() const throw();
	};

	class TooManyItemsException : public std::exception {
        public:
            virtual const char *what() const throw();
	};
};
