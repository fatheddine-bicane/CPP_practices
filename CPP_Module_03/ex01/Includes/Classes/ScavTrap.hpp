#pragma once

#include "./ClapTrap.hpp"

namespace arena {

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name, unsigned int healthPoints,
		  unsigned int energyPoint, unsigned int attackDamage);
	ScavTrap(const ScavTrap& other);
	ScavTrap&	operator=(const ScavTrap& other);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
};

}
