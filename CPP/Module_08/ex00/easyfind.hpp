#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template <typename U, size_t N>
std::vector<U> toVector(U (&arr)[N]) {
	return std::vector<U>(arr, arr + N);
}

template <typename T>
int easyfind(T &cont, int i) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);

	if (it != cont.end())
		return std::distance(cont.begin(), it);
	return (-1);
}
