#include "../Includes/identifier.hpp"
#include <iostream>
#include <exception>

void	identify(Base* p) {
	A* aPtr = dynamic_cast<A*>(p);
	if (aPtr != NULL) {
		std::cout << "The object 'p' pointes to is : A" << '\n';
		return;
	}

	B* bPtr = dynamic_cast<B*>(p);
	if (bPtr != NULL) {
		std::cout << "The object 'p' pointes to is : B" << '\n';
		return;
	}

	C* cPtr = dynamic_cast<C*>(p);
	if (cPtr != NULL) {
		std::cout << "The object 'p' pointes to is : C" << '\n';
		return;
	}
}


void	identify(Base& p) {
	try {
		A& aRef = dynamic_cast<A&>(p);
		(void)aRef;
		std::cout << "The object referneced by 'p' is : A" << '\n';
		return;
	} catch (...) { }

	try {
		B& bRef = dynamic_cast<B&>(p);
		(void)bRef;
		std::cout << "The object referneced by 'p' is : B" << '\n';
		return;
	} catch (...) { }

	try {
		C& cRef = dynamic_cast<C&>(p);
		(void)cRef;
		std::cout << "The object referneced by 'p' is : C" << '\n';
		return;
	} catch (...) { }
}
