#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("PresidentialPardonForm", 25, 5), _target("Unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	(void) src;
	return *this;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (AForm::canExecute(executor)) {
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
