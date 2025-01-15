#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv[i])
	{
		while (*(argv[i]))
			std::cout << (char)std::toupper(*(argv[i]++));
		i++;
	}
	std::cout << std::endl;
	return (0);
}
