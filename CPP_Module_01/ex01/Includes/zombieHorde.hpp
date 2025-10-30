#pragma once

#include "./Zombie.hpp"
#include <string>

namespace zombieHorde {

extern	std::string g_zombiesName;
Zombie*	zombieHorde(int N, std::string name);

}
