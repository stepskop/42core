#include "Harl.hpp"

int main()
{
	Harl logger;
	logger.complain("DEBUG");
	logger.complain("INFO");
	logger.complain("WARNING");
	logger.complain("ERROR");
	logger.complain("FATAL_ERROR");
}
