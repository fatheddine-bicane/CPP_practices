#pragma once

#include "./Interfaces/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria*	_templates[4];

public:
	MateriaSource();
	MateriaSource(AMateria* templates[]);
	MateriaSource(const MateriaSource& other);
	MateriaSource&	operator=(const MateriaSource& other);
	~MateriaSource();
	void	learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};
