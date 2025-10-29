#include "../Includes/zombieSpawn.hpp"
#include <iostream>

int	main() {
	zombieSpawn::Zombie *zombie;
	std::cout << "Adrian is a zombie that lives in the heap.\n"
		<< "Ash is another zombie, he is a chump and lives in the stack.\n";
	zombie = zombieSpawn::newZombie("Adrian");
	zombie->announce();
	zombieSpawn::randomChump("Ash");
	delete zombie;
}
