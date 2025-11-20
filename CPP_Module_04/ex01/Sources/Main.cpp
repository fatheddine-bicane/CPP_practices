#include "../Includes/Classes/Animal.hpp"
#include "../Includes/Classes/Dog.hpp"
#include "../Includes/Classes/Cat.hpp"
#include "../Includes/Classes/WrongAnimal.hpp"
#include "../Includes/Classes/WrongCat.hpp"
#include <iostream>

int main()
{
	zoo::Cat* yuumi = new zoo::Cat("Yuumi");
	zoo::Cat* teemo = new zoo::Cat("Teemo");
	zoo::Dog* naafiri = new zoo::Dog("naafiri");
	zoo::Dog* corki = new zoo::Dog("Corki");
	zoo::Animal* animals[4];

	animals[0] = yuumi;
	animals[1] = teemo;
	animals[2] = naafiri;
	animals[3] = corki;
	animals[0]->makeSound();
	animals[1]->makeSound();
	animals[2]->makeSound();
	animals[3]->makeSound();
	std::cout << "\n----------------------------\n";
	std::cout << "      deleting animals      \n";
	std::cout << "----------------------------\n\n";
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	// delete animals[0];
	// delete animals[1];
	// delete animals[2];
	// delete animals[3];
}
