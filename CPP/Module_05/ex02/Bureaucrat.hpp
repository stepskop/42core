#pragma once

# include <iostream>
# include <exception>
# include <iostream>
# include "AForm.hpp"

class AForm;

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
	int								getGrade() const;

	void	incGrade(int val = 1);
	void	decGrade(int val = 1);

	void	signForm(AForm *form);
	void	executeForm(const AForm &form) const;
};

std::ostream &operator << (std::ostream &stream, const Bureaucrat *obj); 

