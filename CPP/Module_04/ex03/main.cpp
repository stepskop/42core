#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	me->unequip(1);
	me->use(1, *bob);

	me->equip(tmp);
	me->use(1, *bob);

	ICharacter *jozo = new Character(*me);
	jozo->use(0, *me);
	tmp = src->createMateria("cure");
	jozo->equip(tmp);
	jozo->use(2, *me);
	delete bob;
	delete me;
	delete src;
	delete jozo;
	return 0;
}
