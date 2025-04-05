#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *a = NULL;
	Bureaucrat *b = NULL;

	try {
		a = new Bureaucrat("BeanMan", 151);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << ": Instatiating with grade to low." << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << ": Instatiating with grade to high." << std::endl;
	}

	try {
		b = new Bureaucrat("PotatoMan", 3);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << ": Instatiating with grade to low." << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << ": Instatiating with grade to high." << std::endl;
	}

	if (a) {
		std::cout << a << std::endl;
	}
	if (b) {
	}
	std::cout << b << std::endl;

	delete a;
	delete b;
}
