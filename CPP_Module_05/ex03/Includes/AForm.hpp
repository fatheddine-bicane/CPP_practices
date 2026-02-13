#pragma once

#include <istream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	std::string			_target;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	// INFO: Orthodox canonical form
	AForm();
	AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm() = 0;

	// INFO: methods
	const std::string&	getName() const;
	const std::string&	getTarget() const;
	bool	isSigned() const;
	const int&	getToSignGrade() const;
	const int&	getToExecuteGrade() const;
	void	beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const;

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


	class FormNotSignedException : public std::exception {
	private:
		std::string _err;
	public:
		FormNotSignedException(const std::string& err);
		~FormNotSignedException() throw() {}
		const char* what() const throw();
	};

	class UnknownFormNameException : public std::exception {
	private:
		std::string _err;
	public:
		UnknownFormNameException(const std::string& err);
		~UnknownFormNameException() throw() {}
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);
