#include "../Includes/Classes/HumanB.hpp"
#include <iostream>

namespace violence {

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

void	HumanB::attack() {
	if (!_weapon) return;
	std::cout << _name << " attacks with their "
		<< _weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

}
