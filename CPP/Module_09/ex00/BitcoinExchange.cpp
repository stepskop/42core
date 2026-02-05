#include "BitcoinExchange.hpp"

// Validates the first part of the line (date and separator).
// The rest (value) is validated by calling std::stof in getPrices.
bool validateLine(std::string line) {
    size_t year = 4, month = 2, day = 2;
    size_t pos = 0;
    size_t line_length = line.size();

    // Validate "year" part.
    for (size_t i = 0; i < year; i++) {
        if (pos >= line_length || !std::isdigit(line[pos])) {
            return false;
        }
        pos++;
    }

    // Make sure there is a '-' after year (e.g. 2009-).
    if (pos >= line_length || line[pos] != '-') {
        return false;
    }
    pos++;

    // Validate "month" part.
    for (size_t i = 0; i < month; i++) {
        if (pos >= line_length || !std::isdigit(line[pos])) {
            return false;
        }
        pos++;
    }

    // Make sure there is a '-' after year (e.g. 2009-01-).
    if (pos >= line_length || line[pos] != '-') {
        return false;
    }
    pos++;

    // Validate "day" part.
    for (size_t i = 0; i < day; i++) {
        if (pos >= line_length || !std::isdigit(line[pos])) {
            return false;
        }
        pos++;
    }

    // Make sure there is a space after the date (e.g. 2009-01-01 ).
    if (pos >= line_length || !std::isspace(line[pos])) {
        return false;
    }
    pos++;

    // Make sure there is a '|' after the space (e.g. 2009-01-01 |).
    if (pos >= line_length || line[pos] != '|') {
        return false;
    }
    pos++;

    // Make sure there is a space after the '|' (e.g. 2009-01-01 | ).
    if (pos >= line_length || !std::isspace(line[pos])) {
        return false;
    }
    pos++;

    return true;
}

BitcoinExchange::BitcoinExchange(void)
{
    std::ifstream	file("data.csv");
    std::string		line;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open data.csv file" << std::endl;
        return ;
    }

    // Skip the header line
    std::getline(file, line);
    int i = 1;

    while (std::getline(file, line))
    {
        try {
            size_t	commaPos = line.find(',');
            if (commaPos == std::string::npos)
            {
                throw std::runtime_error("Error: Invalid entry format.");
            }

            std::string	date = line.substr(0, commaPos);
            double price = std::stof(line.substr(commaPos + 1));

            _database[date] = price;
        } catch (const std::exception &e) {
            std::cerr << "Error: Exception when parsing data.csv:" << i << ": " << e.what() << std::endl;

            throw std::runtime_error("Error: Failed to parse data.csv file.");
        }

        i++;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &src)
{
	if (this != &src)
		this->_database = src._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::getPrices(std::string input) const
{
    std::ifstream   file(input.c_str());
    std::string     line;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open " << input << " file" << std::endl;
        return ;
    }

    // Skip the header line
    std::getline(file,line);

    while (std::getline(file, line)) {
        size_t	pipePos = line.find('|');

        // If there is no pipe character, the input format is invalid.
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!validateLine(line))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string	date = line.substr(0, pipePos);
        double price;

        // Try to parse the price as a double. If it fails, the input format is invalid.
        try {
            price = std::stof(line.substr(pipePos + 1));
        } catch (const std::exception &e) {
            std::cerr << "Error: bad input, cannot parse price => " << price << std::endl;
            continue;
        }

        // If the price is not in the boundaries.
        if (price < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
         }
        else if (price > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Find the first item in the database whose key is greater than the input date.
        std::map<std::string, float>::const_iterator it = _database.upper_bound(date);

        // We pick one item back, because we want the last item whose key is less than or equal to the input date.
        // If there is no such item, then the highest date in the database is the one we will pick.
        std::pair<std::string, float> db_entry = *--it;
        std::cout << db_entry.first << " => " << price << " = " << db_entry.second * price << std::endl;
    }

    return;
}
