#pragma once

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	// INFO: Orthodox canonical form
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm() {};

	// INFO: methods
	void execute(const Bureaucrat& executor) const;
};
