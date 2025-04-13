#pragma once

#include <exception>

template <class T>
class Array {
private:
	unsigned int	_size;
	T							*_arr;
public:
	Array();
	~Array();
	Array(const Array &src);
	Array(unsigned int n);

	Array &operator = (const Array &src);

	T	&operator [] (unsigned int n);
	T const &operator [] (unsigned int n) const;

	unsigned int	size() const;

	class IndexOutOfBoundsException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#include "Array.tpp"
