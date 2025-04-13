#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array(): _size(0), _arr(NULL) {}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _arr(new T[n]) {}

template <typename T>
Array<T>::Array(const Array<T> &src): _size(src._size), _arr(new T[src._size]) {
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator = (const Array<T> &src) {
	if (this == *src)
		return (*this);
	delete [] _arr;
	_arr = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
	return (*this);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (this->_size);
}

template <typename T>
T	&Array<T>::operator[] (unsigned int i) {
	if (i >= _size)
		throw Array::IndexOutOfBoundsException();
	return (_arr[i]);
}

template <typename T>
T	const &Array<T>::operator[] (unsigned int i) const {
	if (i >= _size)
		throw Array::IndexOutOfBoundsException();
	return (_arr[i]);
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Out of bounds");
}
