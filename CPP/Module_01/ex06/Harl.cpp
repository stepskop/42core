#include "Harl.hpp"

void Harl::complain(std::string level) {
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	size_t min = -1;
	for (size_t i = 0; i < 4; i++) {
		if (level == levels[i])
		{
			min = i;
			break ;
		}
	}
	switch (min) {
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			this->debug();
			// FALLTHROUGH
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			this->info();
			// FALLTHROUGH
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			this->warning();
			// FALLTHROUGH
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
