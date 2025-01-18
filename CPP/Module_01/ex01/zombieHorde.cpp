#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie* zarr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zarr[i].setName(name);
	}
	return (zarr);
}