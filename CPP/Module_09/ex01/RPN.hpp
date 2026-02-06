#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);

		RPN &operator = (const RPN &src);

		static void	evaluate(const std::string &expression);
};

#endif
