#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator = (const BitcoinExchange &src);

		void	getPrices(std::string input) const;
};

#endif
