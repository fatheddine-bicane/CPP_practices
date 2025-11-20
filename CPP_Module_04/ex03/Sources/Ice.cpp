#include "../Includes/Classes/Ice.hpp"
#include "../Includes/colors.hpp"
#include "../Includes/Classes/Interfaces/ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const std::string& color)
	: AMateria("ice"),
	  _color(color) {}

Ice::Ice(const Ice& other)
	: AMateria("ice"),
	  _color(other._color) {}

Ice::~Ice() {}

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
