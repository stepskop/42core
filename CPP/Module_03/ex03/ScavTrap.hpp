#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	protected:
		unsigned int	_energy;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);
		ScavTrap 	&operator = (const ScavTrap &src);
		void		guardGate(void);
		void		attack(const std::string& target);
};

#endif
