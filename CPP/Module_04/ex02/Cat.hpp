#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal 
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(const Cat &src);
		virtual ~Cat(void);

		Cat &operator = (const Cat &src);
		
		virtual void makeSound(void) const;
		void		setIdea(std::string idea, size_t index);
		std::string	getIdea(size_t index);
};

#endif
