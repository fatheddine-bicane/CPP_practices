#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "./Classes/Contact.hpp"
#include "./Classes/PhoneBook.hpp"

#include <exception> // <-- Required for std::exception

// INFO: utils functions

std::string getUserInput();
void	promptUserStart();
void	mainRunner(phonebook::PhoneBook& myPhoneBook);


