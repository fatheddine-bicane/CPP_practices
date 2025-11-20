#include "../Includes/Classes/WrongAnimal.hpp"
#include "../Includes/colors.hpp"
#include <iostream>
#include <string>

namespace zoo {

WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << UNDERLINE
		<< "WrongAnimal default constructor called!\n" RESET;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
	std::cout << UNDERLINE
		<< "WrongAnimal parameterized constructor called!\n" RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << UNDERLINE
		<< "WrongAnimal copy constructor called!\n" RESET;
	_type = other._type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other) {
		return *this;
	}
	_type = other._type;
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "grrrr\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << UNDERLINE
		<< "WrongAnimal destructor called!\n" RESET;
}

}
