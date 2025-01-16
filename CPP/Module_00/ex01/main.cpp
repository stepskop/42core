#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phone_book;
	std::string	cmd;
	while (1)
	{
		std::cout << "Enter the command (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phone_book.add();
		else if (cmd == "SEARCH")
			phone_book.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
		if (std::cin.eof())
			break ;
	}
	std::cout << std::endl;
	return (0);
}
