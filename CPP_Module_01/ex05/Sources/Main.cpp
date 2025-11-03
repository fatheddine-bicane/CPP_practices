#include "../Includes/harlComplaining.hpp"

int main() {
	std::string	level;
	harl::Harl	Harl;

	std::cout << YELLOW "Harl complains at different levels.\n"
		"Please enter a level (DEBUG, INFO, WARNING, ERROR)"
		"to hear him complain:\n> " RESET;
	while (std::getline(std::cin, level)) {
		Harl.complain(level);
		std::cout << YELLOW "> " RESET;
	}
}
