#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		this->_grade = src._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrage(void) const {
	return this->_grade;
}

void	Bureaucrat::incGrade(int val) {
	if (this->_grade - val < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= val;
}

void	Bureaucrat::decGrade(int val) {
	if (this->_grade + val > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += val;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "GradeOverflow";
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "GradeUnderflow";
}

std::ostream &operator << (std::ostream &stream, const Bureaucrat *obj) {
	stream << obj->getName() << ", bureaucrat grade " << obj->getGrage() << std::endl;
	return stream;
}
