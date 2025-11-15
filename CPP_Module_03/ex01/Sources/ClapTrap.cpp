#include "../Includes/Classes/ClapTrap.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

namespace arena {

ClapTrap::ClapTrap()
	: _name(""),
	  _healthPoints(0),
	  _energyPoint(0),
	  _attackDamage(0) {
	std::cout << "Default base class constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _healthPoints(10),
	  _energyPoint(10),
	  _attackDamage(0) {
	std::cout << "Parameterased base class constructor called\n";
}

ClapTrap::ClapTrap(std::string name, unsigned int healthPoints,
		  unsigned int energyPoint, unsigned int attackDamage)
	: _name(name),
	  _healthPoints(healthPoints),
	  _energyPoint(energyPoint),
	  _attackDamage(attackDamage) {}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other._name;
	_healthPoints = other._healthPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	std::cout << "Base class copy constructor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	_healthPoints = other._healthPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoint == 0) {
		return ;
	}
	_energyPoint--;
	std::cout << "ClapTrap " << BLACK BOLD BG_CYAN
		<< _name << RESET " attacks " << BLACK BOLD BG_RED
		<< target << RESET ", causing " << BLOOD_RED
		<< _attackDamage << RESET " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _healthPoints) {
		_healthPoints = 0;
		std::cout << "ClapTrap " << BLACK BOLD BG_CYAN
			<< _name << RESET " took "
			<< BLOOD_RED << amount << RESET << " " <<
			BLOOD_RED BOLD "AND HE DIED!\n" RESET;
		return ;
	}
	_healthPoints -= amount;
	std::cout << "ClapTrap " << BLACK BOLD BG_CYAN
		<< _name << RESET " took damage, and lost "
		<< BLOOD_RED << amount << RESET " health points!\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_healthPoints == 0) {
		return ;
	}
	else if (_energyPoint == 0) {
		return ;
	}
	_energyPoint--;
	_healthPoints += amount;
	std::cout << "ClapTrap " << BLACK BOLD BG_CYAN
		<< _name << RESET " repaired his armor, restoring "
		<< GREEN << amount << RESET " health points!\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Base class destructor called\n";
}

}
