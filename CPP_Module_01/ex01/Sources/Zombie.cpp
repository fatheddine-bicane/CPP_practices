#include "../Includes/zombieHorde.hpp"

#include <iostream>

namespace zombieHorde {

Zombie::Zombie() {
	this->_zombieName = g_zombiesName;
}

void	Zombie::announce() {
	std::cout << this->_zombieName << ":  BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
	std::cout << "<" << this->_zombieName << " is DEAD!>\n";
}

}
