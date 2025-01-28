#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap: Parametric constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout << "FragTrap: Assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead. F" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << ": \"HIGH FIVE GUYS!\"" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->_hitpoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead. F" << std::endl;
		return ;
	} 
	if (this->_energy <= 0) {
		std::cout << "FragTrap " << this->_name << " is exhausted." << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
}
