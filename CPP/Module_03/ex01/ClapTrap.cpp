#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Unnamed"), _hitpoints(10), _attack(0), _energy(10) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _attack(0), _energy(10) {
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_attack = src._attack;
		this->_energy = src._energy;
		this->_hitpoints = src._hitpoints;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " is taking " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
		std::cout << "ClapTrap " << this->_name << " is repairing " << amount << " points of hitpoints!" << std::endl;
}
