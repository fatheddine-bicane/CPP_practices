#include "../Includes/identifier.hpp"
#include <iostream>


int main() {
    std::srand(std::time(NULL));

    std::cout << "===================================================\n"
              << "TEST 1: Identifying types using POINTER (Base*)\n"
              << "===================================================\n";
	for (int i = 0; i < 5; i++) {
		std::cout << "[Pointer Test " << i + 1 << "]: ";
		Base* p = generate();
		identify(p);
		delete p;
	}



    std::cout << "\n===================================================\n"
              << "TEST 2: Identifying types using REFERENCE (Base&)\n"
              << "===================================================\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "[Reference Test " << i + 1 << "]: ";
        Base* p = generate();
		identify(*p);
        delete p;
    }



    std::cout << "\n===================================================\n"
              << "TEST 3: Manual verification of specific types\n"
              << "===================================================\n";
    Base* manualA = new A();
    std::cout << "Manually created A -> "; 
    identify(manualA);
    delete manualA;

    Base* manualB = new B();
    std::cout << "Manually created B -> ";
    identify(*manualB);
    delete manualB;
}
