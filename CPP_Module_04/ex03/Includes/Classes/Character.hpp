#pragma once

#include "./ICharacter.hpp"
#include "AMateria.hpp"

// implements the ICharacter interface
class Character : public ICharacter {
private:
	std::string	_name;
	AMateria* _inventory[4];

	AMateria* _floor[4];
	// WARN: cant unequip more than 4!


public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	Character&	operator=(const Character& other);
	~Character();
	std::string const & getName() const = 0;
	void	equip(AMateria* m);

	// TODO: use a global variable called floor to unequip
	// elelments (maybe resize the global var ptr when its full)
	void	unequip(int idx);

	void	use(int idx, ICharacter& target);
};
