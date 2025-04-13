#include "iter.hpp"

template <typename T>
static void	print(T &n) {
	std::cout << n << std::endl;
}

int main () {
	int arr[] = { 1, 4, 7, 9, 34, 4 };
	::iter(arr, 6, print<int>);

	std::cout << std::endl;

	std::string str_arr[] = { "mirek", "je", "borec" };
	::iter(str_arr, 3, print<std::string>);
}
