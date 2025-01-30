#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ground.hpp"

class Character : public ICharacter
{
	private:
		AMateria *_inventory[4];
		const std::string _name;
	public:
		static Ground	dropped;
		
		Character(void);
		Character(std::string name);
		Character(const Character &src);
		virtual	~Character(void);
		
		Character &operator = (const Character &src);
		
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
