#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *a = NULL;
	Bureaucrat *b = NULL;

	try {
		a = new Bureaucrat("BeanMan", 151); // Will throw
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

	if (b) {
		std::cout << b;
		try {
			b->incGrade(4);
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << ": Incremented grade to high." << std::endl;
		}
		
		try {
			b->decGrade(170);
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << ": Decremented grade too low." << std::endl;
		}

		try {
			b->incGrade();
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << ": Incremented grade to high." << std::endl;
		}
		std::cout << b;
	}

	delete a;
	delete b;
}
