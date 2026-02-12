#include "../Includes/Form.hpp"

// INFO: Orthodox canonical form
Form::Form() :
	_name("Form"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150) {}
	
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {}

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(false),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	this->_isSigned = other._isSigned;
	return *this;
}


// INFO: methods
const std::string& Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_isSigned;
}

const int& Form::getToSignGrade() const {
	return this->_gradeToSign;
}

const int& Form::getToExecuteGrade() const {
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	int bGrade = bureaucrat.getGrade();
	if (this->_gradeToSign < bGrade) {
		throw Form::GradeTooLowException("The bureaucrat's grade is too low");
	}
	this->_isSigned = true;
}

// INFO: exception classes



Form::GradeTooHighException::GradeTooHighException(const std::string& err) :
	_err(err) {}

const char* Form::GradeTooHighException::what() const throw() {
	return this->_err.c_str();
}


Form::GradeTooLowException::GradeTooLowException(const std::string& err) :
	_err(err) {}

const char* Form::GradeTooLowException::what() const throw() {
	return this->_err.c_str();
}




std::ostream& operator<<(std::ostream& lhs, const Form& rhs) {
	lhs << "-Form name: " << rhs.getName()
		<< "\n-Form is signed: " << rhs.isSigned()
		<< "\n-Form grade to sign: " << rhs.getToSignGrade()
		<< "\n-Form grade to execute: " << rhs.getToExecuteGrade() << "\n";
	return lhs;
}
