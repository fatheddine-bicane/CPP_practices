#include "../Includes/phonebook.hpp"
#include "../Includes/Classes/PhoneBook.hpp"
#include <cstdlib>
#include <cctype>

namespace phonebook {

PhoneBook::PhoneBook() {
	this->_contacts = new Contact[10];
	this->_contactCount = 0;
}

std::string	PhoneBook::setContactFields(bool isPhoneNumber, std::string field) {
	std::string contactInfo;

	std::cout << GREEN "Enter " + field + ": " <<  RESET;
	contactInfo = getUserInput();
	while (contactInfo == "") {
		std::cout << RED "A contact field cannot be emthy, try again.\n"
			GREEN "Enter " + field + ": " << RESET;
		contactInfo = getUserInput();
	}
	if (!isPhoneNumber) return contactInfo;
	bool	phoneNumberIsCorrect = false;
	do {
		if (contactInfo.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << RED "A phone number must be composed of numerical values."
				"try again\n" GREEN "Enter Phone Number: " RESET;
			contactInfo = getUserInput();
		} else if (contactInfo.at(0) == '\0') {
			std::cout << RED "A contact field cannot be emthy, try again.\n"
				GREEN "Enter Phone Number: " RESET;
			contactInfo = getUserInput();
		} else {
			phoneNumberIsCorrect = true;
		}
	} while (!phoneNumberIsCorrect);
	return contactInfo;
}


void	PhoneBook::add() {
	keepCountInRange();
	std::cout << GREEN "Please enter the information for the new contact.\n";
	_contacts[_contactCount].setFirstName(setContactFields(false, "First Name"));
	_contacts[_contactCount].setLastName(setContactFields(false, "Last Name"));
	_contacts[_contactCount].setNickName(setContactFields(false, "Nick name"));
	_contacts[_contactCount].setPhoneNumber(setContactFields(true, "Phone Number"));
	_contacts[_contactCount].setDarkestSecret(setContactFields(false, "Darkest Secret"));
	_contactCount++;
}

void	PhoneBook::search() {
	if (_contacts[0].isEmthyContact()) {
		std::cout << RED "Contact's list is emthy!\n" RESET;
		return;
	}
	printExistingContacts();
	searchSpecificContact();
}

void	PhoneBook::printExistingContacts() {
	int width = 10;

	for (int i = 0; i < 10; i++) {
		if (_contacts[i].isEmthyContact()) return;
		std::cout << "|" << std::setw(width) << std::right << i + 1 << "|" ;
		std::cout << std::setw(width) << std::right << getFirstName(i) << "|";
		std::cout << std::setw(width) << std::right << getLastName(i) << "|";
		std::cout << std::setw(width) << std::right << getNickName(i) << "|\n";
	}
}

void	PhoneBook::searchSpecificContact() {
	int	index = getContactIndex();

	if (_contacts[index].isEmthyContact()) {
		std::cout << RED "This contact has not been set yet!\n" RESET;
		return;
	}
	std::cout << YELLOW "First name: " RESET
		<< _contacts[index].getFirstName() + "\n";
	std::cout << YELLOW "Last name: " RESET
		<< _contacts[index].getLastName() + "\n";
	std::cout << YELLOW "Nick name: " RESET
		<< _contacts[index].getNickName() + "\n";
	std::cout << YELLOW "Phone number: " RESET
		<< _contacts[index].getPhoneNumber() + "\n";
	std::cout << YELLOW "Darkest secret: " RESET
		<< _contacts[index].getDarkestSecret() + "\n";

}

int	PhoneBook::getContactIndex() {
	std::string	contactIndex;
	bool	correctIndex = false;
	int	index;

	std::cout << YELLOW "Please enter the desired "
		"contact index to show it's information.\n> " RESET;
	do {
		contactIndex = getUserInput();
		if (contactIndex.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << RED "Contact index must be a number\n" YELLOW "> " RESET;
		}
		index = std::atoi(contactIndex.c_str());
		if (index > 10 || index < 1) {
			std::cout << RED "Contact index cannot be off range [1, 10]\n"
				YELLOW "> " RESET;
		} else {
			correctIndex = true;
		}
	} while(!correctIndex);
	return index - 1;
}

std::string	PhoneBook::getFirstName(int index) {
	std::string	firstName = _contacts[index].getFirstName();
	if (firstName.length() > 10) {
		firstName.erase(10);
		firstName.at(9) = '.';
	}
	return firstName;
}

std::string PhoneBook::getLastName(int index) {
	std::string	lastName = _contacts[index].getLastName();

	if (lastName.length() > 10) {
		lastName.erase(10);
		lastName.at(9) = '.';
	}
	return lastName;
}

std::string PhoneBook::getNickName(int index) {
	std::string	nickName = _contacts[index].getNickName();

	if (nickName.length() > 10) {
		nickName.erase(10);
		nickName.at(9) = '.';
	}
	return nickName;
}

void	PhoneBook::keepCountInRange() {
	if (_contactCount == 10) _contactCount = 0;
}

PhoneBook::~PhoneBook() {
	delete [] this->_contacts;
}

}
