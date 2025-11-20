#include "../Includes/Classes/MateriaSource.hpp"
#include "../Includes/colors.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(AMateria* templates[]) {
	for (int i = 0; i < 4; i++) {
		if (templates[i] != NULL) {
			_templates[i] = templates[i]->clone();
		} else {
			_templates[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._templates[i] != NULL) {
			_templates[i] = other._templates[i]->clone();
		} else {
			_templates[i] = NULL;
		}
	}
}


MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other) {
		return *this;
	}
	for (int i = 0; i < 4; i++) {
		if (other._templates[i] != NULL) {
			_templates[i] = other._templates[i]->clone();
		} else {
			_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL) {
			delete _templates[i];
			_templates[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* toLearn) {
	int i = 0;
	while (i < 4 && _templates[i] != NULL) {
		i++;
	}
	if (i > 4) {
		return;
	}
	_templates[i] = toLearn;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i]->getType() == type) {
			return _templates[i]->clone();
		}
	}
	return NULL;
}
