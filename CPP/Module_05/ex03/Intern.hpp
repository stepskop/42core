#pragma once

#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &src);
	~Intern();

	Intern &operator = (const Intern &src);

	AForm	*makeForm(const std::string &name, const std::string &target) const;
};
