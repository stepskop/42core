#include "BitcoinExchange.hpp"

int main() {

    BitcoinExchange btc_exchange;

    try {
        btc_exchange = BitcoinExchange();
    }
    catch (const std::exception &e) {
        std::cerr << "Error: Exception when initializing BitcoinExchange: " << e.what() << std::endl;
        return 1;
    }

    btc_exchange.getPrices("input.txt");

    return 0;
}
