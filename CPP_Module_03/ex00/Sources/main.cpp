#include "../Includes/Classes/ClapTrap.hpp"

int	main() {
	arena::ClapTrap	talin("Talin");
	arena::ClapTrap	jagar("Jagar");

	talin.attack("Jagar");
	jagar.takeDamage(2);
	jagar.beRepaired(2);
	jagar.attack("Talin");
	talin.takeDamage(10);
}
