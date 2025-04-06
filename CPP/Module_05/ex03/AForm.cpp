#include "AForm.hpp"

AForm::AForm(void): _name("Unknown form"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade): 
	_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src):
	_name(src._name), _isSigned(false), _signGrade(src._execGrade), _execGrade(src._signGrade) {}

AForm::~AForm(void) {}

AForm	&AForm::operator = (const AForm &src) {
	(void) src;
	return *this;
}

const std::string	&AForm::getName(void) const {
	return this->_name; 
}

int	AForm::getSignGrade(void) const {
	return this->_signGrade;
}

int AForm::getExecGrade(void) const {
	return this->_execGrade;
}

bool AForm::getIsSigned(void) const {
	return this->_isSigned;
}

void	AForm::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_isSigned = true;
}

bool	AForm::canExecute(const Bureaucrat &executor) const {
	if (!this->_isSigned)
		throw AForm::UnsignedExecutionException();
	if (this->_execGrade < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	return true;
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char	*AForm::UnsignedExecutionException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator << (std::ostream &o, const AForm *form) {
	o << "FORM: " << form->getName() << std::endl <<
	"\tSigned: " << form->getIsSigned() << std::endl <<
	"\tSign grade: " << form->getSignGrade() << std::endl <<
	"\tExec grade: " << form->getExecGrade() << std::endl;
	return o;
}
