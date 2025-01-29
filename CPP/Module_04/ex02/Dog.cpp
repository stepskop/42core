#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src): Animal()
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Dog &Dog::operator = (const Dog &src)
{
	std::cout << "Dog: Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		// this->_brain = src._brain; - this would be shallow
		for (size_t i = 0; i < 100; i++)
			this->_brain->ideas[i] = src._brain->ideas[i];
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "\"Barky bark\"" << std::endl;
}

void Dog::setIdea(std::string idea, size_t index)
{
	this->_brain->ideas[index] = idea;
}

std::string Dog::getIdea(size_t index)
{
	return this->_brain->ideas[index];
}
