#ifndef GROUND_HPP
# define GROUND_HPP

# include "AMateria.hpp"

class Ground
{
	public:
		Ground(void);
		Ground(const Ground &src);
		~Ground(void);
		
		Ground &operator = (const Ground &src);
		AMateria **items;
		size_t	count;
};

#endif
