#include "../Includes/Classes/ScavTrap.hpp"

int	main() {
	arena::ScavTrap	talin("Talin", 100, 50, 20);
	arena::ScavTrap	mogrus("Mogrus", 100, 50, 20);

	talin.attack("Mogrus");
	mogrus.takeDamage(20);
	mogrus.attack("Talin");
	talin.takeDamage(20);
	talin.beRepaired(20);
	talin.attack("Mogrus");
	mogrus.takeDamage(20);
}
