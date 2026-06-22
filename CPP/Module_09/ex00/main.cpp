#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc_exchange;
        btc_exchange.getPrices(argv[1]);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: Exception using BitcoinExchange: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
