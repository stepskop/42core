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
		std::cout << "Removing " << this->_contacts[this->_index % 8].get_nick();
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
// ┗ ┓┏ ┛ ┻ ┳ ╋ ┫┣

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
}
