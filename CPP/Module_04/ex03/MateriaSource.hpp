#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *_inventory[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		virtual	~MateriaSource(void);

		MateriaSource &operator = (const MateriaSource &src);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif
