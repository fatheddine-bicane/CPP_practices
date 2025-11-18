#pragma once

#include <string>

namespace zoo {

class Animal {
protected:
	std::string	_type;

public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal&	operator=(const Animal& other);
	virtual void	makeSound() const ;
	virtual std::string&	getType() const ;
	virtual ~Animal();
};

}
