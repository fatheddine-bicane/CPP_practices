#include "../Includes/Classes/DiamondTrap.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

namespace arena {

DiamondTrap::DiamondTrap()
	: ClapTrap(),
	  _name(""),
	  _healthPoints(0),
	  _energyPoint(0),
	  _attackDamage(0) {
	std::cout << YELLOW
		<< "DiamindTrap class constructor called\n" RESET;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	  _name(name),
	  _healthPoints(FragTrap::_healthPoints),
	  _energyPoint(ScavTrap::_energyPoint),
	  _attackDamage(FragTrap::_attackDamage) {
	std::cout << YELLOW
		<< "ClapTrap Parameterased class constructor called\n" RESET;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other._name + "_clap_name"),
	  _name(other._name),
	  _healthPoints(other._healthPoints),
	  _energyPoint(other._energyPoint),
	  _attackDamage(other._attackDamage) {
	std::cout << YELLOW
		<< "ClapTrap class copy constructor called\n" RESET;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	_healthPoints = other._healthPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}


void	DiamondTrap::takeDamage(unsigned int amount) {
	if (amount >= _healthPoints) {
		_healthPoints = 0;
		std::cout << "DiamondTrap " << BLACK BOLD BG_YELLOW
			<< _name << RESET " took "
			<< BLOOD_RED << amount << RESET << " " <<
			BLOOD_RED BOLD "AND HE DIED!\n" RESET;
		return ;
	}
	_healthPoints -= amount;
	std::cout << "DiamondTrap " << BLACK BOLD BG_YELLOW
		<< _name << RESET " took damage, and lost "
		<< BLOOD_RED << amount << RESET " health points!\n";
}


void	DiamondTrap::beRepaired(unsigned int amount) {
	if (_healthPoints == 0) {
		return ;
	}
	else if (_energyPoint == 0) {
		return ;
	}
	_energyPoint--;
	_healthPoints += amount;
	std::cout << "DiamondTrap " << BLACK BOLD BG_YELLOW
		<< _name << RESET " repaired his armor, restoring "
		<< GREEN << amount << RESET " health points!\n";
}

void	DiamondTrap::whoAmI() {
	std::cout << "My " << BLACK BOLD BG_YELLOW <<
		"DiamondTrap" RESET << " name is: " << YELLOW
		<< _name << RESET ", And my " BLACK BOLD BG_CYAN
		<< "ClapTrap" RESET << " name is: " << CYAN
		<< ClapTrap::_name << RESET "\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << YELLOW
		<< "ClapTrap class destructor called\n" RESET;
}

}
