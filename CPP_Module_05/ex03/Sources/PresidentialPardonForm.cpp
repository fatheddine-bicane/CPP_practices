#include "../Includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", "DefaultTarget", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm("PresidentialPardonForm", other.getTarget(), 25, 5) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	return *this;
}

// INFO: methods

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	try {
		//check if the executor can execute the form
		AForm::execute(executor);

		// execute the form
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";

	} catch (std::exception& e) {
		throw;
	}
}
