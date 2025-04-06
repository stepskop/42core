#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool							_isSigned;
	const	int					_signGrade;
	const	int					_execGrade;
public:
	AForm(void);
	AForm(const std::string &name, const int signGrade, const int execGrade);
	AForm(const AForm &src);
	virtual ~AForm(void);
	
	AForm	&operator = (const AForm &src);

	const std::string &getName()			const;
	bool							getIsSigned()		const;
	int								getSignGrade()	const;
	int								getExecGrade()	const;
	
	void							beSigned(const Bureaucrat &signer);
	bool							canExecute(const Bureaucrat &executor) const;
	virtual void			execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
	class UnsignedExecutionException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

std::ostream &operator << (std::ostream &o, const AForm *obj);

