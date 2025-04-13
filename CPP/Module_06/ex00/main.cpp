#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./convert <string>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
	
	std::string str = "1e-1000";
	char *str_end;

	errno = 0;
	float f = std::strtof(str.c_str(), &str_end);
	std::cout << "Last char: " << str_end << std::endl << "Value: " << f << std::endl << "Errno: " << errno << std::endl;

}
