#include "../Includes/zombieHorde.hpp"
#include <iostream>
#include <string>

std::string	zombieHorde::g_zombiesName = "";

int main() {
	zombieHorde::Zombie	*zombies;

	zombies = zombieHorde::zombieHorde(10, "Bonesnarl");
	for (int i = 0; i < 10; i++) {
		std::cout << "zombie [" << i + 1 << "]--> ";
		zombies[i].announce();
	}
	std::cout << "a voice: Diiiiiie (bang bang bang...)\n";
	delete[] zombies;
}
