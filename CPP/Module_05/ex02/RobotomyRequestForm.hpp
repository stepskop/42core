#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	const std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm	&operator = (const RobotomyRequestForm &src);

	void							execute(const Bureaucrat &executor) const;
	const std::string	&getTarget() const;
};
