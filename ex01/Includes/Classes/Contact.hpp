#pragma once

// #include "../megaphone.hpp"


#include <iostream>
#include <string>


namespace megaphone {

class Contact {
private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	unsigned int	_phoneNumber;
	std::string		_darkestSecret;
	static int		_contactCount;

public:
	// constructor
	Contact();


	// public methods
	// getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	unsigned int	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	//setters
	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickName(std::string nickName);
	void	setPhoneNumber(unsigned int phoneNumber);
	void	setDarkestSecret(std::string darkestSecret);

};

}
