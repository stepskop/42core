#include "Contact.hpp"

Contact::Contact(void)
{
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

std::string	Contact::get_phone(void)
{
	return (this->_phone);
}

std::string	Contact::get_secret(void)
{
	return (this->_secret);
}

void Contact::set_fname(std::string str)
{
	this->_first_name = str;
}

void Contact::set_lname(std::string str)
{
	this->_last_name = str;
}

void Contact::set_nick(std::string str)
{
	this->_nickname = str;
}

void Contact::set_phone(std::string str)
{
	this->_phone = str;
}

void Contact::set_secret(std::string str)
{
	this->_secret = str;
}
