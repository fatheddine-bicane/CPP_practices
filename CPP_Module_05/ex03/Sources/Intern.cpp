#include "../Includes/Intern.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include <sstream>

// INFO: Orthodox canonical form
Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}


// INFO: methods
int	Intern::hashName(const std::string& name) {
	int result = 0;
	int length = name.length();
	for (int i = length - 1; i > -1; i--) {
		result += name[i];
	}

	int coefficient = 0;
	for (int i = 0; i < length; i++) {
		coefficient += 1 & name[i];
	}

	return coefficient * result;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	switch (hashName(formName)) {
		case ROBOTOMY_REQUEST:
			return new RobotomyRequestForm(target);
			break;
		case SHRUBBERY_CREATION:
			return new ShrubberyCreationForm(target);
			break;
		case PRESIDENTIAL_PARDON:
			return new PresidentialPardonForm(target);
		default:
			std::stringstream err_ss;
			err_ss << "* " << formName << " * is an unknown form type\n";
			throw AForm::UnknownFormNameException(err_ss.str());
	}
	return NULL;
}
