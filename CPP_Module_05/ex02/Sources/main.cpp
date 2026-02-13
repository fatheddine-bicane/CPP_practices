#include "../Includes/Bureaucrat.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 1: ShrubberyCreationForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		ShrubberyCreationForm shrubForm("home");
		Bureaucrat bob("Bob", 137);

		std::cout << shrubForm << std::endl;
		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);
		std::cout << "Check for 'home_shrubbery' file!" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 2: ShrubberyCreationForm - Grade too low" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		ShrubberyCreationForm shrubForm("garden");
		Bureaucrat lowGrade("LowGrade", 150);

		lowGrade.signForm(shrubForm);
		lowGrade.executeForm(shrubForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 3: RobotomyRequestForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		RobotomyRequestForm robotForm("Bender");
		Bureaucrat alice("Alice", 45);

		std::cout << robotForm << std::endl;
		alice.signForm(robotForm);
		alice.executeForm(robotForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 4: RobotomyRequestForm - Grade too low to execute" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		RobotomyRequestForm robotForm("C3PO");
		Bureaucrat midGrade("MidGrade", 50);

		midGrade.signForm(robotForm);
		midGrade.executeForm(robotForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 5: PresidentialPardonForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		PresidentialPardonForm pardonForm("Arthur Dent");
		Bureaucrat president("President", 5);

		std::cout << pardonForm << std::endl;
		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 6: PresidentialPardonForm - Grade too low" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		PresidentialPardonForm pardonForm("Zaphod");
		Bureaucrat lowBureaucrat("LowBureaucrat", 30);

		lowBureaucrat.signForm(pardonForm);
		lowBureaucrat.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 7: Execute unsigned form" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		PresidentialPardonForm pardonForm("Ford Prefect");
		Bureaucrat highGrade("HighGrade", 1);

		highGrade.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
