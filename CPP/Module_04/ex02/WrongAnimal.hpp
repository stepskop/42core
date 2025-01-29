#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string		_type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal(void);
		
		WrongAnimal &operator = (const WrongAnimal &src);
		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif
