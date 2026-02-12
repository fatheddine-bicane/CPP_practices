#include "../Includes/Bureaucrat.hpp"
#include <ostream>

int main() {
    try {
        Bureaucrat taxCollector("Tax collector", 3);
		taxCollector.incrementGrade();
		std::cout << taxCollector.getName() << " graded: "
			<< taxCollector.getGrade() << std::endl;
    } catch (std::exception& e ) {
        std::cerr << e.what() << "\n";
    }
	try {
		Bureaucrat govAccountants("Government accountants", 1);
		govAccountants.incrementGrade();
		std::cout << govAccountants.getName() << " graded: "
			<< govAccountants.getGrade() << std::endl;
    } catch (std::exception& e ) {
        std::cerr << e.what() << "\n";
    }
}
