#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(void)
{
	this->name = "Unnamed";
}

Zombie::~Zombie(void)
{
	std::cout << "Undead " << this->name << " just died\n";
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}