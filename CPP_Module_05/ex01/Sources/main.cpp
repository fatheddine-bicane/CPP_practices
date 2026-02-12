#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"

int main() {

	Form form("tax form", 1, 30);

    try {
        Bureaucrat taxCollector("Tax collector", 3);
		std::cout << form;
		taxCollector.signForm(form);
		taxCollector.incrementGrade();
		taxCollector.incrementGrade();
		taxCollector.signForm(form);
		std::cout << form;
    } catch (std::exception& e ) {
        std::cerr << e.what() << "\n";
    }
	try {
		Bureaucrat govAccountants("Government accountants", 0);
		govAccountants.incrementGrade();
    } catch (std::exception& e ) {
        std::cerr << e.what() << "\n";
    }
}
