#include "Ground.hpp"


Ground::Ground(void)
{
	this->count = 0;
	this->items = new AMateria*[this->count];
}

Ground::Ground(const Ground &src)
{
	*this = src;
}

Ground &Ground::operator=(const Ground &src)
{
	if (this != &src)
		this->items = src.items;
	return *this;
}

Ground::~Ground(void)
{
	for (size_t i = 0; i < this->count; i++)
		if (this->items[i])
			delete this->items[i];
	delete[] this->items;
}

