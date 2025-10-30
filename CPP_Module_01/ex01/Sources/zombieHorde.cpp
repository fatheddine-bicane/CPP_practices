#include "../Includes/zombieHorde.hpp"

namespace zombieHorde {

Zombie*	zombieHorde(int N, std::string name) {
	g_zombiesName = name;
	Zombie	*zombies = new Zombie[N];
	return zombies;
}

}
