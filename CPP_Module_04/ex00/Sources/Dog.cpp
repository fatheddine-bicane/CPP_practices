#include "../Includes/Classes/Dog.hpp"
#include "../Includes/colors.hpp"
#include <iostream>
#include <string>

namespace zoo {

Dog::Dog()
	: Animal("Dog"),
	_name("nameless") {
	std::cout << BRIGHT_BLUE
		<< "Dog default constructor called!\n" RESET;
}

Dog::Dog(const std::string& name)
	: Animal("Dog"),
	  _name(name) {
	std::cout << BRIGHT_BLUE
		<< "Dog parameterized constructor called!\n" RESET;
}

Dog::Dog(const Dog& other)
	: Animal("Dog"),
	  _name(other._name) {
	std::cout << BRIGHT_BLUE
		<< "Dog copy constructor called!\n" RESET;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "WOOF\n";
}

Dog::~Dog() {
	std::cout << BRIGHT_BLUE
		<< "Dog destructor called!\n" RESET;
}

}
