#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	std::string fname = "";
	while (fname == "")
	{
		std::cout << "Enter the first name: "
		std::getline(std:cin, fname);
	}
	std::string lname = "";
	while (lname == "")
	{
		std::cout << "Enter the last name: "
		std::getline(std:cin, lname);
	}
	std::string nick = "";
	while (nick == "")
	{
		std::cout << "Enter the nickname: "
		std::getline(std:cin, nick);
	}
	if (this->_index > 7)
		std::cout << "Removing " << this->_contacts[this->_index % 8].get_nick();
	Contact new_contact(fname, lname, nick);
	this->_contacts[this->_index % 8] = new_contact;
}
