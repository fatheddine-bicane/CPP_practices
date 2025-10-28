#include "../Includes/phonebook.hpp"

int	main() {
	phonebook::PhoneBook	myPhoneBook;
	promptUserStart();
	try {
		mainRunner(myPhoneBook);
	} catch (std::exception& error) {
		// WARN: change errors to be printed on the std::cerr
		std::cerr << RED "An error occurred: "
			<< error.what() << RESET << std::endl;
		std::exit(1);
	}
}
