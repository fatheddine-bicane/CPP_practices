#pragma once

#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	// INFO: Orthodox canonical form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm() {};

	// INFO: methods
	void execute(const Bureaucrat& executor) const;
};
