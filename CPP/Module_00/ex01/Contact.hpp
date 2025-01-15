#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	private:
		std::string	_first_name;
		std::string _last_name;
		std::string _nickname;
	public:
		Contact(std::string first_name, std::string last_name, std::string nickname);
		~Contact(void);
		std::string get_fname(void);
		std::string get_lname(void);
		std::string get_nick(void);
}

#endif
