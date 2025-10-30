
#include "../Includes/zombieSpawn.hpp"
#include <string>

namespace zombieSpawn {

void	randomChump(std::string name) {
	Zombie	chumpZombie(name);

	chumpZombie.announce();
}

}
