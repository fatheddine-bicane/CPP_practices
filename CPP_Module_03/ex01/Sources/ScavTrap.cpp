#include "../Includes/Classes/ScavTrap.hpp"
#include <iostream>
#include "../Includes/colors.hpp"

namespace arena {

ScavTrap::ScavTrap() {
	_healthPoints = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Default derived class constructor called\n";
}

ScavTrap::ScavTrap(std::string name, unsigned int healthPoints,
		  unsigned int energyPoint, unsigned int attackDamage)
	: ClapTrap(name, healthPoints, energyPoint, attackDamage) {
	std::cout << "Parameterased derived class constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	std::cout << "Derived class copy constructor called\n";
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
	std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
		<< _name << RESET " attacks " << BLACK BOLD BG_RED
		<< target << RESET ", causing " << BLOOD_RED
		<< _attackDamage << RESET " points of damage!\n";
}

// void	ScavTrap::takeDamage(unsigned int amount) {
// 	if (amount >= _healthPoints) {
// 		_healthPoints = 0;
// 		std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
// 			<< _name << RESET " took "
// 			<< BLOOD_RED << amount << RESET << " " <<
// 			BLOOD_RED BOLD "AND HE DIED!\n" RESET;
// 		return ;
// 	}
// 	_healthPoints -= amount;
// 	std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
// 		<< _name << RESET " took damage, and lost "
// 		<< BLOOD_RED << amount << RESET " health points!\n";
// }
//
// void	ScavTrap::beRepaired(unsigned int amount) {
// 	if (_healthPoints == 0) {
// 		return ;
// 	}
// 	_healthPoints += amount;
// 	std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
// 		<< _name << RESET " repaired his armor, restoring "
// 		<< GREEN << 2 << RESET " health points!\n";
// }

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << BLACK BOLD BG_PURPLE
		<< _name << RESET " is now in gate keeper mode!\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "Derived class destructor called\n";
}

}
