#include "../Includes/Classes/Cat.hpp"
#include "../Includes/colors.hpp"
#include <iostream>
#include <string>

namespace zoo {

Cat::Cat()
	: Animal("Cat"),
	  _name("nameless") {
	std::cout << BRIGHT_WHITE
		<< "Cat default constructor called!\n" RESET;
}

Cat::Cat(const std::string& name)
	: Animal("Cat"),
	  _name(name) {
	std::cout << BRIGHT_WHITE
		<< "Cat parameterized constructor called!\n" RESET;
}

Cat::Cat(const Cat& other)
	: Animal("Cat"),
	  _name(other._name) {
	std::cout << BRIGHT_WHITE
		<< "Cat copy constructor called!\n" RESET;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "meow\n";
}

Cat::~Cat() {
	std::cout << BRIGHT_WHITE
		<< "Cat destructor called!\n" RESET;
}

}
