#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src) {
	(void) src;
}

Intern	&Intern::operator=(const Intern &src) {
	(void) src;
	return *this;
}

static AForm	*presForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

static AForm	*robForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm	*shrubForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const {
	const std::string forms[] = { "presidential pardon", "robotomy request", "shrubbery creation" };
	AForm *(*form_factory[])(const std::string &target) = { &presForm, &robForm, &shrubForm };
	AForm *res;
	for (int i = 0; i < 3; i++) {
		if (name == forms[i]) {
			res = form_factory[i](target);
			std::cout << "Intern creates " << res->getName() << std::endl;
			return (res);
		}
	}
	std::cout << "Couldn't find suitable form" << std::endl;
	return (NULL);
}
