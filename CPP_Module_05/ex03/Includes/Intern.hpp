#pragma once

#include "./AForm.hpp"

#define ROBOTOMY_REQUEST 17000
#define SHRUBBERY_CREATION 16803
#define PRESIDENTIAL_PARDON 15680

class Intern {
private:
	// INFO: private methods
	int	hashName(const std::string& type);

public:
	// INFO: Orthodox canonical form
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern() {};

	// INFO: methods
	AForm* makeForm(const std::string& formName, const std::string& target);
};
