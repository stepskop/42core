#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->_type = "WrongCat";
	this->_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal()
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

WrongCat &WrongCat::operator = (const WrongCat &src)
{
	std::cout << "WrongCat: Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		// this->_brain = src._brain; - this would be shallow
		for (size_t i = 0; i < 100; i++)
			this->_brain->ideas[i] = src._brain->ideas[i];
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor called" << std::endl;
	delete this->_brain;
}

void WrongCat::makeSound() const
{
	std::cout << "\"Wrong Meow\"" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}

void WrongCat::setIdea(std::string idea, size_t index)
{
	this->_brain->ideas[index] = idea;
}

std::string WrongCat::getIdea(size_t index)
{
	return this->_brain->ideas[index];
}
