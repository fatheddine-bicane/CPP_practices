#include "../Includes/Bureaucrat.hpp"
#include <ostream>

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 1: Create valid Bureaucrat" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob.getName() << ", grade " << bob.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 2: Increment grade" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat taxCollector("Tax collector", 3);
		std::cout << "Before: " << taxCollector.getName() << ", grade " << taxCollector.getGrade() << std::endl;
		taxCollector.incrementGrade();
		std::cout << "After increment: " << taxCollector.getName() << ", grade " << taxCollector.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 3: Decrement grade" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat clerk("Clerk", 100);
		std::cout << "Before: " << clerk.getName() << ", grade " << clerk.getGrade() << std::endl;
		clerk.decrementGrade();
		std::cout << "After decrement: " << clerk.getName() << ", grade " << clerk.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 4: Grade too high at creation (grade 0)" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid.getName() << ", grade " << invalid.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 5: Grade too low at creation (grade 151)" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid.getName() << ", grade " << invalid.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 6: Increment beyond grade 1" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat govAccountants("Government accountants", 1);
		std::cout << "Before: " << govAccountants.getName() << ", grade " << govAccountants.getGrade() << std::endl;
		govAccountants.incrementGrade();
		std::cout << "After: " << govAccountants.getName() << ", grade " << govAccountants.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 7: Decrement beyond grade 150" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		std::cout << "Before: " << intern.getName() << ", grade " << intern.getGrade() << std::endl;
		intern.decrementGrade();
		std::cout << "After: " << intern.getName() << ", grade " << intern.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
