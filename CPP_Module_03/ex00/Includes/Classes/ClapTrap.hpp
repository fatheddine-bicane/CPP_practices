#pragma once

#include <string>

namespace arena {

class ClapTrap {
private:
	std::string		_name;
	unsigned int	_healthPoints;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

public:
	// constructors
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();


	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};
}
