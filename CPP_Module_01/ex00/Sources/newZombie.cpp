#include "../Includes/zombieSpawn.hpp"
#include <string>

namespace zombieSpawn {

Zombie	*newZombie(std::string name) {
	Zombie	*newZombie = new Zombie(name);
	return newZombie;
}

}
