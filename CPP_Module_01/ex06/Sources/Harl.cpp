#include "../Includes/Harl.hpp"

namespace harlFilter {

void	Harl::complain(std::string level) {
	defineLevel(level);
	startComplaining();
}

void	Harl::defineLevel(std::string level) {
	if (level == "DEBUG") {
		_level = DEBUG;
	} else if (level == "INFO") {
		_level = INFO;
	} else if (level == "WARNING") {
		_level = WARNING;
	} else if (level == "ERROR") {
		_level = ERROR;
	} else {
		_level = UNKNOWN;
	}
}

void	Harl::startComplaining() {
	switch (_level) {
		case UNKNOWN:
			unknownLevel();
			break;
		case DEBUG:
			debug();
			/* fall through */
		case INFO:
			info();
			/* fall through */
		case WARNING:
			warning();
			/* fallthrough */
		case ERROR:
			error();
	}
}

void	Harl::debug() {
	std::cout << BLUE "[ DEBUG ]\n" RESET "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-"
		"ketchup burger.\nI really do!\n\n";
}

void	Harl::info() {
	std::cout << GREEN "[ INFO ]\n" RESET "I cannot believe adding extra bacon "
		"costs more money.\nYou didn’t put"
		"enough bacon in my burger! If you did, "
		"I wouldn’t be asking for more!\n\n";
}

void	Harl::warning() {
	std::cout << YELLOW "[ WARNING ]\n" RESET "I think I deserve to have some extra "
		"bacon for free.\nI’ve been coming for years, "
		"whereas you started working here just last month.\n\n";
}

void	Harl::error() {
	std::cout << RED "[ ERROR ]\n" RESET "This is unacceptable! I want to speak "
		"to the manager now.\n\n";
}

void	Harl::unknownLevel() {
	std::cout << PURPLE "[ Probably complaining about"
		" insignificant problems ]\n" RESET;
}

}
