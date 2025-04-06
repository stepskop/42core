#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool							_isSigned;
	const	int					_signGrade;
	const	int					_execGrade;
public:
	Form(void);
	Form(const std::string &name, const int signGrade, const int execGrade);
	Form(const Form &src);
	~Form(void);
	
	Form	&operator = (const Form &src);

	const std::string &getName()			const;
	bool							getIsSigned()		const;
	int								getSignGrade()	const;
	int								getExecGrade()	const;
	
	void							beSigned(const Bureaucrat *signer);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

std::ostream &operator << (std::ostream &o, const Form *obj);

