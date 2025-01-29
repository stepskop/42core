#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src): Animal()
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat &Cat::operator = (const Cat &src)
{
	std::cout << "Cat: Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		// this->_brain = src._brain; - this would be shallow
		for (size_t i = 0; i < 100; i++)
			this->_brain->ideas[i] = src._brain->ideas[i];
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "\"Meow\"" << std::endl;
}

void Cat::setIdea(std::string idea, size_t index)
{
	this->_brain->ideas[index] = idea;
}

std::string Cat::getIdea(size_t index)
{
	return this->_brain->ideas[index];
}
