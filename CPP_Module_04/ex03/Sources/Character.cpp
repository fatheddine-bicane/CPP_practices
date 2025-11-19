#include "../Includes/Classes/Character.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

Character::Character() : _name("") {
	std::cout << UNDERLINE YELLOW
		<< "Ice default constructor called!\n" RESET;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name)
	: _name(name) {
	std::cout << UNDERLINE YELLOW
		<< "Ice parameterized constructor called!\n" RESET;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& other)
	: _name(other._name) {
	std::cout << UNDERLINE YELLOW
		<< "Ice copy constructor called!\n" RESET;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

Character::~Character() {
	std::cout << UNDERLINE YELLOW
		<< "Ice destructor called!\n" RESET;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
		} else {
			break;
		}
	}
}

Character&	Character::operator=(const Character& other) {
	if (this == &other) {
		return *this;
	}
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		} else {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	int i = 0;
	for (; i < 4 && (_inventory[i] != NULL); i++) {
		continue;
	}
	if (i < 4) {
		_inventory[i] = m;
	}
}

void	Character::unequip(int idx) {
	if (idx > 3) {
		return;
	}
	dropMateria(_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	_inventory[idx]->use(target);
	_inventory[idx]->AMateria::use(target);
}
