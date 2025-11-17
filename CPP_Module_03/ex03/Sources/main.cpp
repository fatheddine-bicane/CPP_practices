#include "../Includes/Classes/ScavTrap.hpp"
#include "../Includes/Classes/FragTrap.hpp"
#include "../Includes/Classes/DiamondTrap.hpp"

// FIXME: shallow copy deep copy waaaaaaaaaaaaaaaaaaaa

int	main() {
	arena::ScavTrap	talin("Talin", 100, 50, 20);
	arena::ScavTrap	mogrus("Mogrus", 100, 50, 20);
	arena::FragTrap	jagar("Jagar");
	arena::DiamondTrap	kenen("Kenan");

	kenen.whoAmI();
	kenen.attack("Talin");
	talin.takeDamage(30);
	kenen.attack("Morgus");
	mogrus.takeDamage(30);
	kenen.attack("Jagar");
	jagar.takeDamage(30);
	talin.attack("Mogrus");
	mogrus.takeDamage(20);
	mogrus.attack("Talin");
	talin.takeDamage(20);
	talin.beRepaired(20);
	talin.attack("Mogrus");
	mogrus.takeDamage(20);
	jagar.highFivesGuys();
}
