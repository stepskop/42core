#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("Unnamed_clap_name"){
	this->_name = "Unnamed";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hitpoints = this->FragTrap::_hitpoints;
	this->_energy = this->ScavTrap::_energy;
	this->_attack = this->FragTrap::_attack;
	std::cout << "DiamondTrap: Parametric constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src){
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << "DiamondTrap: Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_attack = src._attack;
		this->_hitpoints = src._hitpoints;
		this->_energy = src._energy;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I " << (this->_hitpoints > 0 ? "am " : "was ") << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
