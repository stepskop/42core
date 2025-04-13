#pragma once

#include <string>
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

class ScalarConverter {
public: 
	static void convert(const std::string &str);
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator = (const ScalarConverter &src);
};
