#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 1: Create valid Form" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Form taxForm("Tax Form", 50, 30);
		std::cout << taxForm << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 2: Form with invalid sign grade (0)" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Form invalidForm("Invalid Form", 0, 30);
		std::cout << invalidForm << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 3: Form with invalid execute grade (151)" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Form invalidForm("Invalid Form", 50, 151);
		std::cout << invalidForm << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 4: Sign form successfully" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Form permitForm("Permit Form", 100, 50);
		Bureaucrat alice("Alice", 90);

		std::cout << "Before signing: " << permitForm << std::endl;
		alice.signForm(permitForm);
		std::cout << "After signing: " << permitForm << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 5: Sign form - grade too low" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Form topSecretForm("Top Secret Form", 10, 5);
		Bureaucrat intern("Intern", 100);

		std::cout << topSecretForm << std::endl;
		intern.signForm(topSecretForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 6: Sign form after promotion" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Form taxForm("Tax Form", 1, 30);
		Bureaucrat taxCollector("Tax collector", 3);

		std::cout << taxForm << std::endl;
		taxCollector.signForm(taxForm);
		std::cout << "Promoting Tax collector..." << std::endl;
		taxCollector.incrementGrade();
		taxCollector.incrementGrade();
		std::cout << taxCollector.getName() << ", grade " << taxCollector.getGrade() << std::endl;
		taxCollector.signForm(taxForm);
		std::cout << taxForm << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 7: Bureaucrat with invalid grade" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat govAccountants("Government accountants", 0);
		std::cout << govAccountants.getName() << ", grade " << govAccountants.getGrade() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
