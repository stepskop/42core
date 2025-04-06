#include "Form.hpp"

Form::Form(void): _name("Unknown form"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &name, const int signGrade, const int execGrade): 
	_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &src):
	_name(src._name), _isSigned(false), _signGrade(src._execGrade), _execGrade(src._signGrade) {}

Form::~Form(void) {}

Form	&Form::operator = (const Form &src) {
	(void) src;
	return *this;
}

const std::string	&Form::getName(void) const {
	return this->_name; 
}

int	Form::getSignGrade(void) const {
	return this->_signGrade;
}

int Form::getExecGrade(void) const {
	return this->_execGrade;
}

bool Form::getIsSigned(void) const {
	return this->_isSigned;
}

void	Form::beSigned(const Bureaucrat *signer) {
	if (signer->getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_isSigned = true;
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

std::ostream &operator << (std::ostream &o, const Form *form) {
	o << "FORM: " << form->getName() << std::endl <<
	"\tSigned: " << form->getIsSigned() << std::endl <<
	"\tSign grade: " << form->getSignGrade() << std::endl <<
	"\tExec grade: " << form->getExecGrade() << std::endl;
	return o;
}
