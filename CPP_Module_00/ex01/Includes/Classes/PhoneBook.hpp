#pragma once

// #include "../phonebook.hpp"
#include "./Contact.hpp"


# ifndef BLUE
#  define BLUE  "\001\033[34m\002"
# endif
# ifndef GREEN
#  define GREEN "\001\033[32m\002"
# endif
# ifndef RED
#  define RED   "\001\033[31m\002"
# endif
# ifndef YELLOW
#  define YELLOW "\001\033[0;33m\002"
# endif
# ifndef RESET
#  define RESET "\001\033[0m\002"
# endif


namespace phonebook {

class PhoneBook {
private:
	// variables
	Contact	*_contacts;
	unsigned int	_contactCount;
	// private methodes
	std::string	setContactFields(bool, std::string);
	void	keepCountInRange();
	std::string	getIndex(int);
	std::string	getFirstName(int);
	std::string	getLastName(int);
	std::string	getNickName(int);
	void	printExistingContacts();
	void	searchSpecificContact();
	int	getContactIndex();

public:
	// constructor
	PhoneBook();

	// public methods
	void	add();
	void	search();

	// destructor
	~PhoneBook();
};

}
