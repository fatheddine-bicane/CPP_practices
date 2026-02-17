#include "../Includes/identifier.hpp"


Base*	generate(void) {
	int arr[3] = {1, 2, 3};
	(void)arr;
	int index = std::rand() % 3;

	if (index == 0) {
		return new A();
	} else if (index == 1) {
		return new B();
	} else {
		return new C();
	}
}
