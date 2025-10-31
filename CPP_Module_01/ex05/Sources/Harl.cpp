#include "../Includes/Harl.hpp"

namespace harl {

void	Harl::complain(std::string level) {
	complainLevel harlComplaining = NULL;

	if (level == "DEBUG") {
		harlComplaining = &Harl::debug;
	} else if (level == "INFO") {
		harlComplaining = &Harl::info;
	} else if (level == "WARNING") {
		harlComplaining = &Harl::warning;
	} else if (level == "ERROR") {
		harlComplaining = &Harl::error;
	} else {
		harlComplaining = &Harl::unknownLevel;
	}
	(this->*harlComplaining)();
}

void	Harl::debug() {
	std::cout << PURPLE "Harl: " BLUE "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-"
		"ketchup burger. I really do!\n" RESET;
}

void	Harl::info() {
	std::cout << PURPLE "Harl: " BLUE "I cannot believe adding extra bacon "
		"costs more money. You didn’t put"
		"enough bacon in my burger! If you did, "
		"I wouldn’t be asking for more!\n" RESET;
}

void	Harl::warning() {
	std::cout << PURPLE "Harl: " BLUE "I think I deserve to have some extra "
		"bacon for free. I’ve been coming for years, "
		"whereas you started working here just last month.\n" RESET;
}

void	Harl::error() {
	std::cout << PURPLE "Harl: " BLUE "This is unacceptable! I want to speak "
		"to the manager now.\n" RESET;
}

void	Harl::unknownLevel() {
	std::cout << RED "(Harl dosent coplain on this level!)\n" RESET;
}

}
