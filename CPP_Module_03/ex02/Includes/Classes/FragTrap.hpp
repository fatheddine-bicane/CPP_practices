#pragma once

#include "./ClapTrap.hpp"

namespace arena {

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap&	operator=(const FragTrap& other);
	void	highFivesGuys(void);
	~FragTrap();
};

}
