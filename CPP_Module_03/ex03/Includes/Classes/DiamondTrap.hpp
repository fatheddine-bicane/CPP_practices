#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

namespace arena {

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string	_name;
	unsigned int	_healthPoints;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void whoAmI();
	~DiamondTrap();
};

}
