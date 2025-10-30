#include "../Includes/Zombie.hpp"
#include <iostream>

namespace zombieSpawn {

Zombie::Zombie(std::string zombieName) {
	this->_zombieName = zombieName;
}

void	Zombie::announce() {
	std::cout << this->_zombieName << ":  BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
	std::cout << "<" << this->_zombieName << " is DEAD!>\n";
}

}
