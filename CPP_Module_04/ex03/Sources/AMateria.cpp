#include "../Includes/Classes/AMateria.hpp"
#include "../Includes/Classes/ICharacter.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

AMateria::AMateria() : _type("") {
	std::cout << UNDERLINE
		<< "AMateria default constructor called!\n" RESET;
}

AMateria::AMateria(std::string const& type)
	: _type(type) {
	std::cout << UNDERLINE
		<< "AMateria parameterized constructor called!\n" RESET;
}

AMateria::AMateria(const AMateria& other)
	: _type(other._type) {
	std::cout << UNDERLINE
		<< "AMateria copy constructor called!\n" RESET;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this == &other) {
		return *this;
	}
	_type = other._type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << UNDERLINE
		<< "AMateria destructor called!\n" RESET;
}

std::string const& AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << UNDERLINE "* A materia is used on "
		<< BOLD << target.getName() << "!\n" RESET;
}
