#include "../Includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", "DefaultTarget", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm("ShrubberyCreationForm", other.getTarget(), 145, 137) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	return *this;
}

// INFO: methods

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	try {
		//check if the executor can execute the form
		AForm::execute(executor);

		// execute the form
		std::ofstream	target((getTarget() + "_shrubbery").c_str());
		std::stringstream	shrubberyTree;

		shrubberyTree << "       _-_" << '\n';
		shrubberyTree << "    /~~   ~~\\" << '\n';
		shrubberyTree << " /~~         ~~\\" << '\n';
		shrubberyTree << "{               }" << '\n';
		shrubberyTree << " \\  _-     -_  /" << '\n';
		shrubberyTree << "   ~  \\\\ //  ~" << '\n';
		shrubberyTree << "_- -   | | _- _" << '\n';
		shrubberyTree << "  _ -  | |   -_" << '\n';
		shrubberyTree << "      // \\\\" << '\n';
		shrubberyTree << '\n';

		target << shrubberyTree.str() << '\n';
		target << shrubberyTree.str() << '\n';
		target << shrubberyTree.str() << '\n';
		target.close();

	} catch (std::exception& e) {
		throw;
	}
}
