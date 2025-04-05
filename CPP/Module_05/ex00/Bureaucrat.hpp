#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <ostream>

class Bureaucrat {
private:
	const std::string		_name;
	int									_grade;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);
	
	Bureaucrat &operator = (const Bureaucrat &src);
	
	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	const std::string &getName() const;
	int								getGrage() const;

	void	incGrade(int val = 1);
	void	decGrade(int val = 1);
};

std::ostream &operator << (std::ostream &stream, const Bureaucrat *obj); 

#endif
