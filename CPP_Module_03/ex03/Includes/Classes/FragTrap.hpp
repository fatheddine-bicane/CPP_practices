#pragma once

#include "./ClapTrap.hpp"

namespace arena {

class FragTrap : virtual public ClapTrap {
protected:
	unsigned int	_healthPoints;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap&	operator=(const FragTrap& other);
	void	highFivesGuys(void);
	~FragTrap();
};

}
