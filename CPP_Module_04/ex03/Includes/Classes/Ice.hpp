#pragma once

#include "./AbstractClasses/AMateria.hpp"

class Ice : public AMateria {
private:
	std::string	_color;

public:
	Ice();
	Ice(const std::string& type);
	Ice(const Ice& other);
	Ice&		operator=(const Ice& other);
	~Ice();
	AMateria*	clone() const ;
	void		use(ICharacter& target);
};
