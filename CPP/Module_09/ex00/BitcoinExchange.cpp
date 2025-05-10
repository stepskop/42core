#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>
#include <string>


static void error_exit(std::string err) {
	std::cout << "Error: " << err << std::endl;
	exit(1);
}

static std::map<std::string, double> loadFile(std::string input) {
    std::ifstream       in_file(input);
   	if (in_file.fail())
		error_exit("Opening the input file");


    std::map<std::string, double> map;

    (void)input;


    return map;
}

BitcoinExchange::BitcoinExchange() {
    std::ifstream       in_file("data.csv");
	std::string		    line;
	std::stringstream   line_stream;
	std::string         key;
	std::string         value;

	if (in_file.fail())
		error_exit("Opening the database file");
	getline(in_file, line);
	while (!in_file.eof()) {
		getline(in_file, line);
		line_stream = std::stringstream(line);
		getline(line_stream, key, ',');
		getline(line_stream, value);
		this->_database[key] = std::stod(value.c_str());
	}
	in_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src): _database(src._database) {};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src)
        this->_database = src._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {};

void    BitcoinExchange::getPrices(std::string input) const {
    std::map<std::string, double> map = loadFile(input);

}
