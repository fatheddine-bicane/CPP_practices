#include "../Includes/zombieSpawn.hpp"
#include <iostream>

int	main() {
	zombieSpawn::Zombie *zombie;
	std::cout << "Deathclaw is a zombie that lives in the heap.\n"
		<< "Grimfang is another zombie, he is a chump and lives in the stack.\n";
	zombie = zombieSpawn::newZombie("Deathclaw");
	zombie->announce();
	zombieSpawn::randomChump("Grimfang");
	delete zombie;
}
