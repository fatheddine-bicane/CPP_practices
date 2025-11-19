#include "../Includes/Classes/Cure.hpp"
#include "../Includes/colors.hpp"
#include "../Includes/Classes/Interfaces/ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << UNDERLINE GREEN
		<< "Cure default constructor called!\n" RESET;
}

Cure::Cure(const std::string& color)
	: AMateria("cure"),
	  _color(color) {
	std::cout << UNDERLINE GREEN
		<< "Cure parameterized constructor called!\n" RESET;
}

Cure::Cure(const Cure& other)
	: AMateria("cure"),
	  _color(other._color) {
	std::cout << UNDERLINE GREEN
		<< "Cure copy constructor called!\n" RESET;
}

Cure::~Cure() {
	std::cout << UNDERLINE GREEN
		<< "Cure destructor called!\n" RESET;
}

Cure&	Cure::operator=(const Cure& other) {
	if (this == &other) {
		return *this;
	}
	_color = other._color;
	return *this;
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << GREEN "* heals "
		<< target.getName() << " 's wounds *\n" RESET;
}
