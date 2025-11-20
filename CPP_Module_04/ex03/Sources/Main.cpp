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
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	/*-------------------------------*/

	/*-------------------------------*/
	// create two characters
	ICharacter* mike = new Character("mike");
	ICharacter* bob = new Character("bob");
	/*-------------------------------*/

	/*-------------------------------*/
	AMateria* tmp;
	// mike equip materia's
	tmp = src->createMateria("ice");
	mike->equip(tmp);
	tmp = src->createMateria("cure");
	mike->equip(tmp);
	// bob equip materia's
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	/*-------------------------------*/


	/*-------------------------------*/
	// now fight time !!!
	mike->use(0, *bob);
	bob->use(0, *mike);
	mike->use(1, *bob);
	bob->use(1, *mike);
	/*-------------------------------*/

	/*-------------------------------*/
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
