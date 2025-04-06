#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("RobotomyRequestForm", 72, 45), _target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	(void) src;
	return *this;
}

const std::string &RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	static int	success_rate = 0;
	if (AForm::canExecute(executor)) {
		std::cout << "** Drilling noises **....";
		if (success_rate++ % 2)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomization failed" << std::endl;
		if (success_rate == 2)
			success_rate = 0;
	}
}
