#include "AMateria.hpp"

AMateria::AMateria(void): _type("unknown")
{}

AMateria::AMateria(const std::string &type): _type(type)
{}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria::~AMateria(void)
{}

std::string const &AMateria::getType(void) const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "Base AMateria::use is unimplemented" << std::endl;
}
