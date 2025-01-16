#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string _last_name;
		std::string _nickname;
	public:
		Contact(void);
		~Contact(void);
		std::string get_fname(void);
		std::string get_lname(void);
		std::string get_nick(void);
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nick(std::string str);
};

#endif
