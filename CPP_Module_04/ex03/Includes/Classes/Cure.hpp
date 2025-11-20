#pragma once

#include "./AbstractClasses/AMateria.hpp"

class Cure : public AMateria {
private:
	std::string	_color;

public:
	Cure();
	Cure(const std::string& color);
	Cure(const Cure& other);
	Cure&		operator=(const Cure& other);
	~Cure();
	AMateria*	clone() const ;
	void		use(ICharacter& target);
};
