#include "Zombie.hpp"

int main()
{
	Zombie *z = newZombie("Johhny");
	z->announce();
	delete z;
	randomChump("Boris");
}