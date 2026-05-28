#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: usage: ./PmergeMe <positive integers>" << std::endl;
		return 1;
	}

	PmergeMe sorter;

	try
	{
	    // You can pass additional boolean argument controlling whether we allow duplicates.
		sorter.sort(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
