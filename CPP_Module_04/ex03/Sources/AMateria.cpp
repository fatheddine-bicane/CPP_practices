#include "../Includes/Classes/AbstractClasses/AMateria.hpp"
#include "../Includes/Classes/Interfaces/ICharacter.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

AMateria::AMateria() : _type("") {}

AMateria::AMateria(std::string const& type)
	: _type(type) {}

AMateria::AMateria(const AMateria& other)
	: _type(other._type) {}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this == &other) {
		return *this;
	}
	_type = other._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	(void) target;
}
