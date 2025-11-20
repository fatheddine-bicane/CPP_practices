#include "../Includes/colors.hpp"
#include "../Includes/floor.hpp"
#include "../Includes/Classes/Character.hpp"
#include "../Includes/Classes/Cure.hpp"
#include "../Includes/Classes/Ice.hpp"
#include "../Includes/Classes/MateriaSource.hpp"
#include <iostream>

t_floor*	g_floor = NULL;

int main()
{
	/*-------------------------------*/
	// create a materia source
	std::cout << BLACK BG_PURPLE "A materia source is ceated!\n" << RESET;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	/*-------------------------------*/

	/*-------------------------------*/
	// create two characters
	std::cout << BLACK BG_PURPLE
		<< "Two character joined the arena: Mike and Bob!\n" << RESET;
	ICharacter* mike = new Character("mike");
	ICharacter* bob = new Character("bob");
	/*-------------------------------*/

	/*-------------------------------*/
	AMateria* tmp;
	// mike equip materia's
	std::cout << BLACK BG_PURPLE
		<< "Mike is equiping materia's from the source!\n" << RESET;
	tmp = src->createMateria("ice");
	mike->equip(tmp);
	tmp = src->createMateria("cure");
	mike->equip(tmp);
	// bob equip materia's
	std::cout << BLACK BG_PURPLE
		<< "Bob is equiping materia's from the source!\n" << RESET;
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	/*-------------------------------*/


	/*-------------------------------*/
	std::cout << BLACK BG_PURPLE
		<< "Mike and Bob are about to start fighting!!!!\n" << RESET;
	// now fight time !!!
	mike->use(0, *bob);
	bob->use(0, *mike);
	mike->use(1, *bob);
	bob->use(1, *mike);
	/*-------------------------------*/

	/*-------------------------------*/
	std::cout << BLACK BG_PURPLE
		<< "Fight is over, Mike and Bob are now unequiping there materia's\n" << RESET;
	// mike and bob are unequiping there materia's
	mike->unequip(0);
	mike->unequip(1);
	bob->unequip(0);
	bob->unequip(1);
	/*-------------------------------*/

	delete bob;
	delete mike;
	delete src;
	cleanFloor();
	return 0;
}
