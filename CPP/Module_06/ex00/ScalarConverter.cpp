#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &src) {
	(void)src;
	return *this;
}

void ScalarConverter::convert(const std::string &str) {

	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	}

	if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}

	if (str == "nan" || str == "nanf") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
	}

	if (str.length() == 1 && !std::isdigit(str[0])) {
		if (std::isprint(str[0]))
			std::cout << "char: '" << str[0] << "'" << std::endl; 
		else
			std::cout << "char: Not displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		return ;
	}

	errno = 0;
	char *last;

	long int num = std::strtol(str.c_str(), &last, 10);
	if (!*last) {
		if (errno != 0 || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
			std::cout << "Cannot convert" << std::endl;
			return ;
		}

		if (num >= 0 && num <= 127 && std::isprint(static_cast<char>(num)))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl; 
		else {
			if (num < 0 || num > 127)
				std::cout << "char: impossible" << std::endl;
			else if (num < ' ' || num > '~')
				std::cout << "char: Non displayable" << std::endl;
		}

		std::cout << "int: " << num << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		return ;
	}

	errno = 0;
	float numf = std::strtof(str.c_str(), &last);
	if (std::string(last) == "f" || std::string(last) == "F" ) {
		if (errno != 0 || numf > std::numeric_limits<float>::max() || numf < std::numeric_limits<float>::min()) {
			std::cout << "Cannot convert" << std::endl;
			return ;
		}

		if (numf >= 0 && numf <= 127 && std::isprint(static_cast<char>(numf)))
			std::cout << "char: '" << static_cast<char>(numf) << "'" << std::endl; 
		else {
			if (numf < 0 || numf > 127)
				std::cout << "char: impossible" << std::endl;
			else if (numf < ' ' || numf > '~')
				std::cout << "char: Non displayable" << std::endl;
		}

		if (numf < static_cast<float>(std::numeric_limits<int>::max()) && numf > static_cast<float>(std::numeric_limits<int>::min()))
			std::cout << "int: " << static_cast<int>(numf) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << numf << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(numf) << std::endl;
		return ;
	}

	errno = 0;
	double numd = std::strtod(str.c_str(), &last);
	if (!*last) {
		if (errno != 0 || numd > std::numeric_limits<double>::max() || numd < std::numeric_limits<double>::min()) {
			std::cout << "Cannot convert" << std::endl;
			return ;
		}
		if (numd >= 0 && numd <= 127 && std::isprint(static_cast<char>(numd)))
			std::cout << "char: '" << static_cast<char>(numd) << "'" << std::endl; 
		else {
			if (numd < 0 || numd > 127)
				std::cout << "char: impossible" << std::endl;
			else if (numd < ' ' || numd > '~')
				std::cout << "char: Non displayable" << std::endl;
		}

		if (numd < static_cast<double>(std::numeric_limits<int>::max()) && numd > static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: " << static_cast<int>(numd) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(numd) << "f" << std::endl;
		std::cout << "double: " << numd << std::endl;
		return ;
	}
	std::cout << "Cannot convert" << std::endl;
}
