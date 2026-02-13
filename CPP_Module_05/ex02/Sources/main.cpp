#include "../Includes/Bureaucrat.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"


int main() {
	ShrubberyCreationForm form("home");

    try {
        Bureaucrat jhon("Jhon", 138);
		jhon.executeForm(form);
		jhon.signForm(form);
		jhon.executeForm(form);
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
