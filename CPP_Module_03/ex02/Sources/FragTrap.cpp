#include "../Includes/Classes/FragTrap.hpp"
#include <iostream>
#include "../Includes/colors.hpp"

namespace arena {

FragTrap::FragTrap() {
	std::cout << GREEN
		<< "FragTrap default class constructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_healthPoints = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << GREEN
		<< "FragTrap Parameterased class constructor called\n" RESET;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << GREEN
		<< "FragTrap class copy constructor called\n" RESET;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << BLACK BOLD BG_GREEN
		<< _name << RESET " said: Yo guys, can wee all do a high five!!\n";
}

FragTrap::~FragTrap() {
	std::cout << GREEN
		<< "FragTrap class destructor called!\n" RESET;
}

}
