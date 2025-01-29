#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain 
{
	public:
		std::string ideas[100];
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);
		
		Brain &operator = (const Brain &src);
};

#endif
