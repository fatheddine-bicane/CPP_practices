#pragma once

#include <istream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:


	// INFO: Orthodox canonical form

	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form() {};

	// INFO: methods
	const std::string&	getName() const;
	bool	isSigned() const;
	const int&	getToSignGrade() const;
	const int&	getToExecuteGrade() const;
	void	beSigned(const Bureaucrat& bureaucrat);









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

std::ostream& operator<<(std::ostream& lhs, const Form& rhs);
