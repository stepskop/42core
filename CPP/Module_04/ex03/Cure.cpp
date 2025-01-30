#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{}

Cure::Cure(const Cure &src): AMateria(src)
{
	*this = src;
}

Cure::~Cure(void)
{}

Cure &Cure::operator=(const Cure &src)
{
	(void)src;
	return *this;
}

void	Cure::use(ICharacter &target)
{
	std::cout << " * heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure *Cure::clone(void) const
{
	return new Cure(*this);
}
