#pragma once

#include <string>

namespace zoo {

class WrongAnimal {
protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator=(const WrongAnimal& other);
	void	makeSound() const;
	virtual ~WrongAnimal();
};

}
