#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp): weapon(wp){
	this->name = name;
}

HumanA::~HumanA(void) {

}

void HumanA::attack(void) {
	std::cout << name << " attack with their " << this->weapon.getType() << std::endl;
}
