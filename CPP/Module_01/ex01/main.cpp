#include "Zombie.hpp"

int main ()
{
	Zombie *z = zombieHorde(9, "Truffle");
	for (int i = 0; i < 9; i++)
		z[i].announce();
	delete[] z;
}