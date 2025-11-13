#include "../Includes/Classes/ClapTrap.hpp"
#include "../Includes/arena.hpp"

namespace arena {

ClapTrap::ClapTrap()
	: _name(""),
	  _hitPoints(10),
	  _energyPoint(10),
	  _attackDamage(10) {}


ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoint(10),
	  _attackDamage(10) {}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	applyDamage(target);
}

}
