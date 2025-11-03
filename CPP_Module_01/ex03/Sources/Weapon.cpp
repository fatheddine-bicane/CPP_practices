#include "../Includes/Classes/Weapon.hpp"

namespace violence {

Weapon::Weapon(std::string type) {
	this->_type = type;
}

const std::string& Weapon::getType() {
	std::string& typeRef = this->_type;
	return typeRef;
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}

}
