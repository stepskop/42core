#include "Character.hpp"

Ground		Character::dropped = Ground();

Character::Character(void): _name("unnamed")
{
	for(size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	for(size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &src)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	for (size_t i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

const std::string &Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	for (size_t i = 0; i < Character::dropped.count; i++)
	{
		if (Character::dropped.items[i] == m)
		{
			Character::dropped.items[i] = NULL;
			break ;
		}
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	AMateria **tmp;
	if (idx < 4 && this->_inventory[idx])
	{
		tmp = Character::dropped.items;
		Character::dropped.items = new AMateria*[Character::dropped.count + 1];
		for (size_t i = 0; i < Character::dropped.count; i++)
			dropped.items[i] = tmp[i];
		dropped.items[Character::dropped.count] = this->_inventory[idx];
		Character::dropped.count++;
		this->_inventory[idx] = NULL;
		if (tmp)
			delete[] tmp;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "There is no item to use :(" << std::endl;
}
