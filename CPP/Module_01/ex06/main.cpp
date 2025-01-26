#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl logger;

	if (argc != 2) {
		std::cout << "Please provide minimum log level" << std::endl;
		return 1;
	}
	logger.complain(argv[1]);
}
