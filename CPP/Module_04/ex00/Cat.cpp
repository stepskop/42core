#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src): Animal()
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator = (const Cat &src)
{
	std::cout << "Cat: Assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "\"Meow\"" << std::endl;
}
