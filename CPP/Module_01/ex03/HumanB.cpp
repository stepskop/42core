#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}
HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &wp) {
	this->weapon = &wp;
}

void HumanB::attack(void) {
	std::string used_weapon = "bare hands";
	if (this->weapon)
		used_weapon = this->weapon->getType();
	std::cout << name << " attacks with their " << used_weapon << std::endl;
}
