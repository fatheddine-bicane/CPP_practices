#include "../Includes/arena.hpp"
#include <iostream>

namespace arena {

void	mainRunner(void) {
	ClapTrap	talin("Talin");
	ClapTrap	jagar("Jagar");

	talin.attack("Jagar");
	std::cout << "ClapTrap " << BLACK BOLD BG_YELLOW "Talin" RESET
		" attacks " << BLACK BOLD BG_PURPLE "Jagar" RESET
		", causing " << BLOOD_RED << 2 << RESET " points of damage!\n";
	jagar.takeDamage(2);
	jagar.beRepaired(2);
	std::cout << "ClapTrap " << BLACK BOLD BG_PURPLE "Jagar" RESET
		" repaired his armor, restoring " << GREEN << 2
		<< RESET " health points!\n";
	jagar.attack("Talin");
	std::cout << "ClapTrap " << BLACK BOLD BG_PURPLE "Jagar" RESET
		" attacks " << BLACK BOLD BG_YELLOW "Talin" RESET
		", causing " << BLOOD_RED << 10 << RESET " points of damage!\n";
	talin.takeDamage(10);
	std::cout << "ClapTrap " << BLACK BOLD BG_YELLOW "Talin" RESET
		" " BLOOD_RED BOLD BG_RED "HAS DIED!\n" RESET;
}

}
