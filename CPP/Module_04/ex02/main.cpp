#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal *animal = new Animal();
	{
		Cat	leo = Cat();

		{
			Cat	milo = Cat();
			milo.setIdea("great idea", 0);
			// With assignement
			leo = milo;
			milo.setIdea("another great idea", 0);
			// With copy constructor
			Cat	simba = Cat(milo);
			milo.setIdea("bad idea", 0);
			std::cout << "Milo 1st idea: " << milo.getIdea(0) << std::endl;
			std::cout << "Simba 1st idea: " << simba.getIdea(0) << std::endl;
		}
		std::cout << "Leo 1st idea: " << leo.getIdea(0) << std::endl;
		std::cout << std::endl << std::endl;

		}
	{
		Animal *zoo[100];
		for (size_t i = 0; i < 100; i++)
		{
			if (i < 50)
				zoo[i] = new Dog();
			else
	    		zoo[i] = new Cat();
			zoo[i]->makeSound();
		}
		for (size_t i = 0; i < 100; i++)
			delete zoo[i];
	}
	{
		WrongAnimal *zoo[100];
		for (size_t i = 0; i < 100; i++)
		{
	    	zoo[i] = new WrongCat();
			zoo[i]->makeSound();
		}
		for (size_t i = 0; i < 100; i++)
			delete zoo[i]; //This will not call WrongCat constructor since it is not virtual - Brain will not get deleted - MEM LEAK
	}
	std::cout << std::endl << std::endl;
	return 0;
}
