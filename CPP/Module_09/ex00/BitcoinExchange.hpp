#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();

        BitcoinExchange &operator = (const BitcoinExchange &src);

        void    getPrices(std::string input) const;
};
