#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base *generate() {
	std::srand(std::time(0));
  int random = std::rand() % 3;

	Base *res;

	switch (random) {
		case 0:
			res = new A;
			break ;
		case 1:
			res = new B;
			break ;
		default:
			res = new C;
			break ;
	}
	return res;
}

static void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

static void identify(Base &p) {
	try {
		A &ref = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void) ref;
		return ;
	} catch (std::exception &e) {}
	try {
		B &ref = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void) ref;
		return ;
	} catch (std::exception &e) {}
	try {
		C &ref = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void) ref;
		return ;
	} catch (std::exception &e) {}
}

int main() {
	Base *ptr;

	ptr = generate();
	Base &ref = *ptr;

	identify(ref);
	identify(ptr);
}
