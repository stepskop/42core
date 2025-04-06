#include "Form.hpp"

int main(void) {
	Bureaucrat *a = new Bureaucrat("BeanMan", 140);
	Bureaucrat *b = new Bureaucrat("PotatoMan", 1);

	Form *formA = NULL;
	Form *formB = NULL;

	try {
		formA = new Form("Roast potatoes", 10, 170); // Will throw
	} catch (std::exception &e) {
		std::cout << "Instatiating form with invalid grade: " << e.what() << std::endl;
	}

	try {
		formB = new Form("Boil beans", 1, 35);
	} catch (std::exception &e) {
		std::cout << "Instatiating form with invalid grade: " << e.what() << std::endl;
	}

	if (formB) {
		std::cout << formB;
		a->signForm(formB);
		b->signForm(formB);
		std::cout << formB;
	}

	delete a;
	delete b;
	delete formA;
	delete formB;
}
