#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("Generic wrong animal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &src)
{
	std::cout << "WrongAnimal: Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\"Doing generic wrong animal sound\"" << std::endl;
}
