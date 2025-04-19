#include <iostream>
#include "Array.hpp"

struct s_test {
	int a;
	char b;
};

int main(int, char**)
{
	Array<int> emptyArray;
	std::cout << std::endl << "Empty array size: " << emptyArray.size() << std::endl;
	
	try {
		std::cout << "Empty array[5]: " << emptyArray[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Array<int> intArray(5);
	int i = 0;
	while (i < 5) {
		intArray[i] = i;
		i++;
	}
	std::cout << std::endl << "Int array size: " << intArray.size() << std::endl;
	std::cout << "Int array: ";
	i = 0;
	while (i < 5) {
		std::cout << intArray[i] << " ";
		i++;
	}
	std::cout << std::endl;


	Array<double> doubleArray(10);
	i = 0;
    while (i < 10) {
		doubleArray[i] = i / 2.0;
		i++;
	}
	std::cout << std::endl << "Double array size: " << doubleArray.size() << std::endl;
	std::cout << "Double array: ";
	i = 0;
	while (i < 10) {
		std::cout << doubleArray[i] << " ";
		i++;
	}
	std::cout << std::endl;

	Array<int> intArrayCopy(intArray);
	std::cout << std::endl << "Int array copy size: " << intArrayCopy.size() << std::endl;
	std::cout << "Int array copy: ";
	i = 0;
	while (i < 5) {
			std::cout << intArrayCopy[i] << " ";
			i++;
	}
	std::cout << std::endl;

	Array<double> doubleArrayAssignment = doubleArray;
	std::cout << std::endl << "Double array assignment size: " << doubleArrayAssignment.size() << std::endl;
	std::cout << "Double array assignment: ";
	i = 0;
	while (i < 10) {
			std::cout << doubleArrayAssignment[i] << " ";
			i++;
	}
	std::cout << std::endl;

	const Array<int> constIntArray(intArray);
	std::cout << std::endl << "Const int array size: " << constIntArray.size() << std::endl;
	std::cout << "Const int array: ";
	i = 0;
	while (i < 5) {
		std::cout << constIntArray[i] << " ";
		i++;
	}
	std::cout << std::endl;

	Array<s_test> structArray(6);
	i = 0;
	while (i < 6) {
		structArray[i].a = i;
		structArray[i].b = 'a' + i;
		i++;
	}
	std::cout << std::endl << "Struct array size: " << structArray.size() << std::endl;
	std::cout << "Struct array: ";
	i = 0;
	while (i < 6) {
		std::cout << structArray[i].a << structArray[i].b << " ";
		i++;
	}
	std::cout << std::endl;

	return (0);
}
