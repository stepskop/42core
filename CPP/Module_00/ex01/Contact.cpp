#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
}

Contact::~Contact(void)
{
}

std::string	Contact::get_fname(void)
{
	return (this->_first_name);
}

std::string Contact::get_lname(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nick(void)
{
	return (this->_nickname);
}
