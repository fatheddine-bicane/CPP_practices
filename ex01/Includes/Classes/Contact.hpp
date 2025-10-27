#pragma once

// #include "../phonebook.hpp"


#include <iostream>
#include <string>


namespace phonebook {

class Contact {
private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_phoneNumber;
	std::string		_darkestSecret;
	bool			_empthyContact;

public:
	// constructor
	Contact();


	// public methods
	// getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	bool	isEmthyContact() const;
	//setters
	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickName(std::string nickName);
	void	setPhoneNumber(std::string phoneNumber);
	void	setDarkestSecret(std::string darkestSecret);

};

}
