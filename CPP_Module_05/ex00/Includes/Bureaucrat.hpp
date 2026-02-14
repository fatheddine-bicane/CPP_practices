#pragma once

#include <exception>
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>

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

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs);
