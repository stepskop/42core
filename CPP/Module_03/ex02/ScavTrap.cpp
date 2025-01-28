#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap: Parametric constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	std::cout << "ScavTrap: Assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	return *this;
}

void ScavTrap::guardGate(void) {
	std::cout << "Scavtrap " << this->_name << ": \"You shall not pass!\"" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead. F" << std::endl;
		return ;
	} 
	if (this->_energy <= 0) {
		std::cout << "ScavTrap " << this->_name << " is exhausted." << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
}
