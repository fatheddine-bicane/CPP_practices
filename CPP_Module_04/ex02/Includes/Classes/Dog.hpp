#pragma once

#include "./Animal.hpp"
#include "./Brain.hpp"

namespace zoo {

class Dog : public Animal {
private:
	std::string	_name;
	Brain*		_brain;

public:
	Dog();
	Dog(const std::string& name);
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	void	makeSound() const ;
	std::string&	getType() const ;
	~Dog();
};

}
