#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "---- CONSTRUCTORS ----" << std::endl;
	DiamondTrap bulbizar("Bulbizar");
	DiamondTrap pikachu;

	std::cout << std::endl << "---- VALID ACTIONS ----" << std::endl;
	bulbizar.whoAmI();
	bulbizar.attack("Carapuce");
	pikachu.whoAmI();
	pikachu.highFivesGuys();
	pikachu.guardGate();

	std::cout << std::endl << "---- INVALID ACTIONS ----" << std::endl;
	bulbizar.takeDamage(1000);
	bulbizar.attack("Carapuce");

	for (int i = 0; i < 51; i++) {
		pikachu.attack("Carapuce");
	}

	std::cout << std::endl << "---- DESTRUCTORS ----" << std::endl;
	return 0;
}
