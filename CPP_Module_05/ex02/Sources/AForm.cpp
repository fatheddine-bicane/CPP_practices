#include "../Includes/AForm.hpp"

// INFO: Orthodox canonical form
AForm::AForm() :
	_name("Form"),
	_target("Target"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150) {}
	
AForm::AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute) :
	_name(name),
	_target(target),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_target(other._target),
	_isSigned(false),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	this->_isSigned = other._isSigned;
	this->_target = other._target;
	return *this;
}

AForm::~AForm() {}


// INFO: methods
const std::string& AForm::getName() const {
	return this->_name;
}

const std::string&	AForm::getTarget() const {
	return this->_target;
}

bool AForm::isSigned() const {
	return this->_isSigned;
}

const int& AForm::getToSignGrade() const {
	return this->_gradeToSign;
}

const int& AForm::getToExecuteGrade() const {
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	int bGrade = bureaucrat.getGrade();
	if (this->_gradeToSign < bGrade) {
		throw AForm::GradeTooLowException("The bureaucrat's grade is too low");
	}
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (this->_isSigned == false) {
		throw AForm::FormNotSignedException("Form not signed");
	}
	if (executor.getGrade() > this->_gradeToExecute) {
		throw AForm::GradeTooLowException("Bureaucrat's grade is too low");
	}
}

// INFO: exception classes
AForm::GradeTooHighException::GradeTooHighException(const std::string& err) :
	_err(err) {}

const char* AForm::GradeTooHighException::what() const throw() {
	return this->_err.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& err) :
	_err(err) {}

const char* AForm::GradeTooLowException::what() const throw() {
	return this->_err.c_str();
}


AForm::FormNotSignedException::FormNotSignedException(const std::string& err) :
	_err(err) {}

const char* AForm::FormNotSignedException::what() const throw() {
	return this->_err.c_str();
}


//--------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& lhs, const AForm& rhs) {
	lhs << "-Form name: " << rhs.getName()
		<< "\n-Form target: " << rhs.getTarget()
		<< "\n-Form is signed: " << rhs.isSigned()
		<< "\n-Form grade to sign: " << rhs.getToSignGrade()
		<< "\n-Form grade to execute: " << rhs.getToExecuteGrade() << "\n";
	return lhs;
}
//--------------------------------------------------------------------------------
