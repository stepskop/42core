#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain &Brain::operator= (const Brain &src)
{
	std::cout << "Brain: Assignment operator called" << std::endl;
	if (this != &src)
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	return *this;
}
