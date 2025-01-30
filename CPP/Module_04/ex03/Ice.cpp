#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{}

Ice::Ice(const Ice &src): AMateria(src)
{
	*this = src;
}

Ice::~Ice(void)
{}

Ice &Ice::operator=(const Ice &src)
{
	(void)src;
	return *this;
}

void Ice::use(ICharacter &target)
{
	std::cout << " * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice *Ice::clone(void) const
{
	return new Ice(*this);
}
