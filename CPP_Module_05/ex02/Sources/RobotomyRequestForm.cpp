#include "../Includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", "DefaultTarget", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm("RobotomyRequestForm", other.getTarget(), 72, 45) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	return *this;
}

// INFO: methods

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	try {
		//check if the executor can execute the form
		AForm::execute(executor);

		// execute the form
		std::cout << "* DRILLING NOISES * Bzzzzz... Vrrrrrr... *" << std::endl;

		std::srand(std::time(NULL));
		if (std::rand() % 2 == 0) {
			std::cout << getTarget() << " has been robotomized successfully\n";
		} else {
			std::cout << "Robotomy failed on " << getTarget() << '\n';
		}

	} catch (std::exception& e) {
		throw;
	}
}
