#include "../Includes/Classes/ClapTrap.hpp"
#include "../Includes/arena.hpp"
#include <iostream>

namespace arena {

ClapTrap::ClapTrap()
	: _name(""),
	  _healthPoints(0),
	  _energyPoint(0),
	  _attackDamage(0) {
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _healthPoints(10),
	  _energyPoint(10),
	  _attackDamage(0) {
	std::cout << "Parameterased constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other._name;
	_healthPoints = other._healthPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	std::cout << "Copy constructor called\n";
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
	(void)target;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_healthPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_healthPoints == 0) {
		return ;
	}
	_healthPoints += amount;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
}

}
