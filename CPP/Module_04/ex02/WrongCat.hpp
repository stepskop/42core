#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal 
{
	private:
		Brain *_brain;
	public:
		WrongCat(void);
		WrongCat(const WrongCat &src);
		~WrongCat(void);

		WrongCat &operator = (const WrongCat &src);
		
		void makeSound(void) const;
		void		setIdea(std::string idea, size_t index);
		std::string	getIdea(size_t index);
};

#endif
