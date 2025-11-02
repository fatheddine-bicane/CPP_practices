#include "../Includes/Harl.hpp"

namespace harl {

void	Harl::complain(std::string level) {
	Harl::complainLevel	harlComplainLevel = NULL;

	defineLevel(level, harlComplainLevel);
	(this->*harlComplainLevel)();
}


void	Harl::defineLevel(
	std::string level, Harl::complainLevel& harlComplainLevel) {
	if (level == "DEBUG") {
		harlComplainLevel = &Harl::debug;
	} else if (level == "INFO") {
		harlComplainLevel = &Harl::info;
	} else if (level == "WARNING") {
		harlComplainLevel = &Harl::warning;
	} else if (level == "ERROR") {
		harlComplainLevel = &Harl::error;
	} else {
		harlComplainLevel = &Harl::unknownLevel;
	}
}

void	Harl::debug() {
	std::cout << BLACK << BG_BLUE "Harl:" BLUE
		" I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-"
		"ketchup burger. I really do!\n" RESET;
}

void	Harl::info() {
	std::cout << BLACK << BG_BLUE "Harl:" BLUE
		" I cannot believe adding extra bacon "
		"costs more money. You didn’t put"
		"enough bacon in my burger! If you did, "
		"I wouldn’t be asking for more!\n" RESET;
}

void	Harl::warning() {
	std::cout << BLACK << BG_BLUE "Harl:" BLUE
		" I think I deserve to have some extra "
		"bacon for free. I’ve been coming for years, "
		"whereas you started working here just last month.\n" RESET;
}

void	Harl::error() {
	std::cout << BLACK << BG_BLUE "Harl:" BLUE
		" This is unacceptable! I want to speak "
		"to the manager now.\n" RESET;
}

void	Harl::unknownLevel() {
	std::cout << RED "(Harl dosent coplain on this level!)\n" RESET;
}

}
