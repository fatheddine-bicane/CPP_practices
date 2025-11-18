#include "../Includes/Classes/Animal.hpp"
#include "../Includes/colors.hpp"
#include <iostream>
#include <string>

namespace zoo {

Animal::Animal() : _type("typeless") {
	std::cout << UNDERLINE
		<< "Animal default constructor called!\n" RESET;
}
//
Animal::Animal(const std::string& type) : _type(type) {
	std::cout << UNDERLINE
		<< "Animal parameterized constructor called!\n" RESET;
}

Animal::~Animal() {
	std::cout << UNDERLINE
		<< "Animal destructor called!\n" RESET;
}

}
