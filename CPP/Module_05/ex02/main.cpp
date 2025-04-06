#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
	Bureaucrat *a = new Bureaucrat("BeanMan", 140);
	Bureaucrat *b = new Bureaucrat("PotatoMan", 1);

	PresidentialPardonForm	*presidentForm = new PresidentialPardonForm("Mirek");
	ShrubberyCreationForm		*shrubberyForm = new ShrubberyCreationForm("garden");
	RobotomyRequestForm			*robotomyForm = new RobotomyRequestForm("Your leg");

	a->signForm(presidentForm); // Couldn't be signed
	b->signForm(shrubberyForm);
	b->signForm(robotomyForm);

	a->executeForm(*presidentForm); // Not signed
	b->signForm(presidentForm);
	a->executeForm(*presidentForm); // Grade to low
	b->executeForm(*presidentForm);

	b->executeForm(*shrubberyForm);
	b->executeForm(*robotomyForm);
	b->executeForm(*robotomyForm);
	b->executeForm(*robotomyForm);
	b->executeForm(*robotomyForm);

	delete a;
	delete b;
	delete presidentForm;
	delete shrubberyForm;
	delete robotomyForm;
}
