#include "FragTrap.hpp"

int main(void) {
	std::cout << "---- CONSTRUCTORS ----" << std::endl;
	FragTrap bulbizar("Bulbizar");
	FragTrap pikachu;

	std::cout << std::endl << "---- VALID ACTIONS ----" << std::endl;
	bulbizar.attack("Carapuce");
	bulbizar.highFivesGuys();

	std::cout << std::endl << "---- INVALID ACTIONS ----" << std::endl;
	bulbizar.takeDamage(1000);
	bulbizar.attack("Carapuce");

	for (int i = 0; i < 51; i++) {
		pikachu.attack("Carapuce");
	}

	std::cout << std::endl << "---- DESTRUCTORS ----" << std::endl;
	return 0;
}
