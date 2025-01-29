#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal 
{
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(const Dog &src);
		virtual ~Dog(void);

		Dog &operator = (const Dog &src);
		
		virtual void makeSound(void) const;
		void		setIdea(std::string idea, size_t index);
		std::string	getIdea(size_t index);
};

#endif
