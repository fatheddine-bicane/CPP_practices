#include "../Includes/Classes/FragTrap.hpp"
#include <iostream>
#include "../Includes/colors.hpp"

namespace arena {

FragTrap::FragTrap()
	: _healthPoints(0),
	  _energyPoint(0),
	  _attackDamage(0) {
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

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other),
	  _healthPoints(other._healthPoints),
	  _energyPoint(other._energyPoint),
	  _attackDamage(other._attackDamage) {
	std::cout << GREEN
		<< "FragTrap class copy constructor called\n" RESET;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	_healthPoints = other._healthPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return *this;
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
