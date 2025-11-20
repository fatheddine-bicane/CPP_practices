#include "../Includes/Classes/Animal.hpp"
#include "../Includes/colors.hpp"
#include <iostream>
#include <string>

namespace zoo {

Animal::Animal() : _type("typeless") {
	std::cout << UNDERLINE
		<< "Animal default constructor called!\n" RESET;
}

Animal::Animal(const std::string& type) : _type(type) {
	std::cout << UNDERLINE
		<< "Animal parameterized constructor called!\n" RESET;
}

Animal::Animal(const Animal& other) {
	std::cout << UNDERLINE
		<< "Animal copy constructor called!\n" RESET;
	_type = other._type;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this == &other) {
		return *this;
	}
	_type = other._type;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "grrrr\n";
}

std::string&	Animal::getType() const {
	return (std::string&)_type;
}

Animal::~Animal() {
	std::cout << UNDERLINE
		<< "Animal destructor called!\n" RESET;
}

}
