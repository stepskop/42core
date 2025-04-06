#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat *a = new Bureaucrat("BeanMan", 140);
	Bureaucrat *b = new Bureaucrat("PotatoMan", 1);

	Intern intern;
	AForm	*presidentForm = intern.makeForm("presidential pardon", "Mirek");
	AForm	*shrubberyForm = intern.makeForm("shrubbery creation", "garden");
	AForm	*robotomyForm = intern.makeForm("robotomy request", "Your leg");
	AForm *unknownForm = intern.makeForm("avoid taxes", "My bank account");

	if (unknownForm) 
		b->signForm(unknownForm);

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
	delete unknownForm;
	delete presidentForm;
	delete shrubberyForm;
	delete robotomyForm;
}
