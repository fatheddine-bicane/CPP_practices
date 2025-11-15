#include "../Includes/Classes/ScavTrap.hpp"
#include <iostream>
#include "../Includes/colors.hpp"

namespace arena {

ScavTrap::ScavTrap() {
	_healthPoints = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << PURPLE
		<< "ScavTrap default class constructor called\n" RESET;
}

ScavTrap::ScavTrap(std::string name, unsigned int healthPoints,
		  unsigned int energyPoint, unsigned int attackDamage)
	: ClapTrap(name, healthPoints, energyPoint, attackDamage) {
	std::cout << PURPLE
		<< "ScavTrap Parameterased class constructor called\n" RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	std::cout << PURPLE
		<< "ScavTrap class copy constructor called\n" RESET;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	_healthPoints = other._healthPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (_energyPoint == 0) {
		return ;
	}
	_energyPoint--;
	std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
		<< _name << RESET " attacks " << BLACK BOLD BG_RED
		<< target << RESET ", causing " << BLOOD_RED
		<< _attackDamage << RESET " points of damage!\n";
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
		<< _name << RESET " is now in gate keeper mode!\n";
}

ScavTrap::~ScavTrap() {
	std::cout << PURPLE
		<< "ScavTrap class destructor called\n" RESET;
}

}
