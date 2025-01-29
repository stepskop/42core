#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal()
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator = (const WrongCat &src)
{
	std::cout << "WrongCat: Assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "\"Wrong Meow\"" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}
