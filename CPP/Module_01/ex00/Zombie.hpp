#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	private:
		std::string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif