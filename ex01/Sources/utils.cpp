#include "../Includes/phonebook.hpp"
#include <exception> // <-- Required for std::exception

std::string getUserInput() {
	std::string	result;

	std::getline(std::cin, result, '\n');
	if (std::cin.eof()) throw std::runtime_error("EOF detected (Ctrl + D)");
	return result;
}

void	promptUserStart() {
	std::cout << BLUE "Please enter one of the following commands:\n"
		<< "ADD -> to add a conract to the contact list.\n"
		<< "SEARCH -> to search for an existing contact.\n"
		<< "EXIT -> to exit the phonebook application.\n";
}

void	mainRunner(phonebook::PhoneBook& myPhoneBook) {
	std::string userInput;

	while (true) {
		std::cout << BLUE "> " RESET;
		userInput = getUserInput();
		if (userInput == "ADD" || userInput == "add") {
			myPhoneBook.add();
		} else if (userInput == "SEARCH" || userInput == "search") {
			myPhoneBook.search();
		} else if (userInput == "EXIT" || userInput == "exit") {
			std::exit(0);
		} else {
			std::cout << RED "[" RESET << userInput << RED "] "
				"Unknown command please try again.\n" RESET;
		}
	}
}
