#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm("ShrubberyCreationForm", 25, 5), _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 25, 5), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	(void) src;
	return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (AForm::canExecute(executor)) {
		std::string	target = this->_target;
		std::ofstream	file (target.append("_shrubbery").c_str());
		file << "       /\\\n";
    file << "      /**\\\n";
    file << "     /****\\\n";
    file << "    /******\\\n";
    file << "   /********\\\n";
    file << "  /**********\\\n";
    file << "      ||\n";
    file << "      ||\n";
		file.close();
	}
}
