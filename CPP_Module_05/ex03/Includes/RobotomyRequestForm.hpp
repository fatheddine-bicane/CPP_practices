#pragma once

#include "./AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	// INFO: Orthodox canonical form
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm() {};

	// INFO: methods
	void execute(const Bureaucrat& executor) const;
};
