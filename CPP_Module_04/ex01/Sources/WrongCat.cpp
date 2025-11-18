#include "../Includes/Classes/WrongCat.hpp"
#include "../Includes/colors.hpp"
#include <iostream>
#include <string>

namespace zoo {

WrongCat::WrongCat()
	: WrongAnimal("WrongCat"),
	  _name("nameless") {
	std::cout << ORANGE
		<< "WrongCat default constructor called!\n" RESET;
}

WrongCat::WrongCat(const std::string& name)
	: WrongAnimal("WrongCat"),
	  _name(name) {
	std::cout << ORANGE
		<< "WrongCat parameterized constructor called!\n" RESET;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal("WrongCat"),
	  _name(other._name) {
	std::cout << ORANGE
		<< "WrongCat copy constructor called!\n" RESET;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this == &other) {
		return *this;
		_name = other._name;
	}
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << _name << ": meow\n";
}

WrongCat::~WrongCat() {
	std::cout << ORANGE
		<< "WrongCat destructor called!\n" RESET;
}

}
