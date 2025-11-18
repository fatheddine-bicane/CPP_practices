#include "../Includes/Classes/AMateria.hpp"
#include "../Includes/Classes/ICharacter.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << UNDERLINE "* The materia " << this->_type
		<< " is used on " << BOLD << target.getName() << "!\n" RESET;
}
