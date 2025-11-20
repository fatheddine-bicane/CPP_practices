#include "../Includes/Classes/Animal.hpp"
#include "../Includes/Classes/Dog.hpp"
#include "../Includes/Classes/Cat.hpp"
#include "../Includes/Classes/WrongAnimal.hpp"
#include "../Includes/Classes/WrongCat.hpp"
#include <iostream>

int main()

{
	const zoo::Animal* meta = new zoo::Animal();
	const zoo::Animal* cat = new zoo::Dog();
	const zoo::Animal* dog = new zoo::Cat();
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound(); //will output the cat sound!
	cat->makeSound();
	meta->makeSound();
	delete meta;
	delete cat;
	delete dog;

	std::cout << "\n----------------------------\n";
	std::cout << "     no virtual function    \n";
	std::cout << "----------------------------\n\n";
	const zoo::WrongAnimal* wrongCat = new zoo::WrongCat();
	wrongCat->makeSound();
	delete wrongCat;
	return 0;
}
