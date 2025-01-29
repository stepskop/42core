#include "Animal.hpp"

Animal::Animal(void): _type("Generic animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator = (const Animal &src)
{
	std::cout << "Animal: Assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal: Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "\"Doing generic animal sound\"" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->_type;
}
