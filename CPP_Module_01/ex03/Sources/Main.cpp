#include "../Includes/violence.hpp"

int	main() {
	{
		violence::Weapon club = violence::Weapon("carbine");
		violence::HumanA bob("Bob", club);
		bob.attack();
		club.setType("handgun");
		bob.attack();
	}
	{
		violence::Weapon club = violence::Weapon("carbine");
		violence::HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("handgun");
		jim.attack();
	}
	return 0;
}
