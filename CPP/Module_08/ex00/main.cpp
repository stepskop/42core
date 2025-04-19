#include "easyfind.hpp"

int main() {
	int arr[] = { 79,15,789,4,6,79 };

	std::vector<int> vec = toVector(arr);

	int index = easyfind(vec, 79);

	if (index == -1) {
		std::cout << "Not found in container" << std::endl;
		return (1);
	}
	std::cout << "Found on index: " << index << std::endl;
}
