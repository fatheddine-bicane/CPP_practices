#include "../Includes/Classes/Ice.hpp"
#include "../Includes/colors.hpp"
#include "../Includes/Classes/ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << UNDERLINE CYAN
		<< "Ice default constructor called!\n" RESET;
}

Ice::Ice(const std::string& color)
	: AMateria("ice"),
	  _color(color) {
	std::cout << UNDERLINE CYAN
		<< "Ice parameterized constructor called!\n" RESET;
}

Ice::Ice(const Ice& other)
	: AMateria("ice"),
	  _color(other._color) {
	std::cout << UNDERLINE CYAN
		<< "Ice copy constructor called!\n" RESET;
}

Ice::~Ice() {
	std::cout << UNDERLINE CYAN
		<< "Ice destructor called!\n" RESET;
}

Ice&	Ice::operator=(const Ice& other) {
	if (this == &other) {
		return *this;
	}
	_color = other._color;
	return *this;
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << CYAN "* shoots an ice bolth at "
		<< target.getName() << " *\n" RESET;
}
