#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <sstream>

class Form;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

public:

	// INFO: Orthodox canonical form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade = 150);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat() {};

	// INFO: methods
	const std::string&	getName() const;
	const int&	getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(Form& form);



	// INFO: exception classes
	class GradeTooHighException : public std::exception {
	private:
		std::string _err;
	public:
		GradeTooHighException(const std::string& err);
		~GradeTooHighException() throw() {}
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	private:
		std::string _err;
	public:
		GradeTooLowException(const std::string& err);
		~GradeTooLowException() throw() {};
		const char* what() const throw();
	};
};
