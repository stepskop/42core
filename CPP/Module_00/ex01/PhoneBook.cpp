#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	std::string str = "";
	if (this->_index > 7)
		std::cout << "Removing " << this->_contacts[this->_index % 8].get_nick() << std::endl;
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, str);
	}
	this->_contacts[this->_index % 8].set_fname(str);
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the last name: ";
		std::getline(std::cin, str);
	}
	this->_contacts[this->_index % 8].set_lname(str);
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, str);
	}
	this->_contacts[this->_index % 8].set_nick(str);
	this->_index++;
}

static std::string	format_field(std::string str)
{
	std::string res;
	int	str_len = str.size();
	int	i = -1;
	if (str_len < 10)
	{
		while (++i + str_len != 10)
			res.append(" ");
		res.append(str);
		return (res);
	}
	else if (str_len > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

void	PhoneBook::search(void)
{
	std::cout << "┏----------┯----------┯----------┯----------┓" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "┣----------╋----------╋----------╋----------┫" << std::endl;

	int	i = -1;

	while (++i < 8 && this->_contacts[i].get_fname().size())
	{
		std::cout << "|         " << i;
		std::cout << "|" << format_field(this->_contacts[i].get_fname());
		std::cout << "|" << format_field(this->_contacts[i].get_lname());
		std::cout << "|" << format_field(this->_contacts[i].get_nick()) << "|" << std::endl;
	}
	std::cout << "┗----------┻----------┻----------┻----------┛" << std::endl;
	if (!i)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	std::string str = "";

	std::cout << "Select contact (0 - " << i - 1 << "): ";
	std::getline(std::cin, str);
	while (!std::cin.eof() && (str.size() != 1 || (str[0] < '0' || str[0] > (i - 1) + '0')))
	{
		std::cout << "Invalid index" << std::endl;
		std::cout << "Select contact (0 - " << i - 1 << "): ";
		std::getline(std::cin, str);
	}
	std::cout << std::endl << "Viewing contact [" << str << "]:" << std::endl << std::endl; 
	std::cout << this->_contacts[str[0] - '0'].get_fname() << std::endl;
	std::cout << this->_contacts[str[0] - '0'].get_lname() << std::endl;
	std::cout << this->_contacts[str[0] - '0'].get_nick() << std::endl << std::endl;
}
