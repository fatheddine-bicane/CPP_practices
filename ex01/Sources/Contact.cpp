#include "../Includes/phonebook.hpp"

namespace phonebook {

// constructors
Contact::Contact() {
	this->_empthyContact = true;
};

// getters
std::string	Contact::getFirstName() const {
	return	_firstName;
}

std::string	Contact::getLastName() const {
	return	_lastName;
}

std::string	Contact::getNickName() const {
	return _nickName;
}

std::string	Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return _darkestSecret;
}

bool	Contact::isEmthyContact() const {
	return _empthyContact;
}


// INFO: setters

// WARN: contact member var cant be emthy 
// "A saved contact can’t have empty fields" <- subject !!

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
	this->_empthyContact = false;
}




}
