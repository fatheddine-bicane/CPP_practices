#include "../Includes/phonebook.hpp"

int	main() {
	phonebook::PhoneBook	myPhoneBook;
	promptUserStart();
	try {
		mainRunner(myPhoneBook);
	} catch (std::exception& error) {
		std::cout << RED "An error occurred: " << error.what() << RESET << std::endl;
		std::exit(1);
	}
}
