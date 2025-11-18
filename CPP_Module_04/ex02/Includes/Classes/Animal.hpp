#pragma once

#include <string>

namespace zoo {

class Animal {
protected:
	std::string	_type;

public:
	Animal();
	Animal(const std::string& type);
	virtual void	makeSound() const = 0;
	virtual std::string&	getType() const  = 0;
	virtual ~Animal();
};

}
