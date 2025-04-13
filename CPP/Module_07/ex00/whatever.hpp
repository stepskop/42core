#pragma once

template	<typename T>
const T &max (const T &a, const T &b) {
	if (a >= b)
		return a;
	return b;
};

template	<typename U>
const U &min (const U &a, const U &b) {
	if (a <= b)
		return a;
	return b;
};

template <typename V>
void	swap(V &a, V &b) {
	V tmp = a;
	a = b;
	b = tmp;
}
