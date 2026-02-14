#include "../Includes/Bureaucrat.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/Intern.hpp"

int main() {
	Intern intern;
	AForm* form;

	std::cout << "========================================" << std::endl;
	std::cout << "TEST 1: Intern creates ShrubberyCreationForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			Bureaucrat bob("Bob", 137);
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 2: Intern creates RobotomyRequestForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("robotomy request", "Bender");
		if (form) {
			std::cout << *form << std::endl;
			Bureaucrat alice("Alice", 45);
			alice.signForm(*form);
			alice.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 3: Intern creates PresidentialPardonForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;
			Bureaucrat president("President", 5);
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 4: Intern with unknown form name" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("unknowon form", "target");
		if (form)
			delete form;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 5: Intern with empty form name" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("", "target");
		if (form)
			delete form;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 6: Intern with typo in form name" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("shrubbery creaton", "garden");
		if (form)
			delete form;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 7: Intern with random gibberish" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		form = intern.makeForm("asdfghjkl123", "nowhere");
		if (form)
			delete form;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
