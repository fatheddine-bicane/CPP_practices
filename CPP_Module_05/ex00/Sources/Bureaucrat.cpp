#include "../Includes/Bureaucrat.hpp"

// INFO: Orthodox canonical form
Bureaucrat::Bureaucrat() :
	_name("Bureaucrat"),
	_grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name) {
	if (grade < 1) {
		std::stringstream err_ss;
		err_ss << "The grade: " << grade << " is too high!\n";
		throw Bureaucrat::GradeTooHighException(err_ss.str());
	} else if (grade > 150) {
		std::stringstream err_ss;
		err_ss << "The grade: " << grade << " is too low!\n";
		throw Bureaucrat::GradeTooLowException(err_ss.str());
	} else {
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name),
	_grade(other._grade) {}


Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	this->_grade = other._grade;
	return *this;
}



// INFO: methods
const std::string& Bureaucrat::getName() const {
	return this->_name;
}

const int& Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1) {
		std::stringstream err_ss;
		err_ss << "The new grade: " << this->_grade - 1 << " is too high!\n";
		throw Bureaucrat::GradeTooHighException(err_ss.str());
	}
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {

	if (this->_grade + 1 > 150) {
		std::stringstream err_ss;
		err_ss << "The new grade: " << this->_grade + 1 << " is too high!\n";
		throw Bureaucrat::GradeTooLowException(err_ss.str());
	}
	this->_grade++;
}


// INFO: exception classes

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& err) :
	_err(err) {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return this->_err.c_str();
}


Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& err) :
	_err(err) {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return this->_err.c_str();
}


