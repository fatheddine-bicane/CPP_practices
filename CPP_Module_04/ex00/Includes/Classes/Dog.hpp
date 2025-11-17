#pragma once

#include "./Animal.hpp"

namespace zoo {

class Dog : public Animal {
private:
	std::string	_name;

public:
	Dog();
	Dog(const std::string& name);
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	void	makeSound() const ;
	// void	getType() const ;
	~Dog();
};

}
