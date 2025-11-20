#pragma once

#include "./Animal.hpp"

namespace zoo {

class Cat : public Animal {
private:
	std::string	_name;

public:
	Cat();
	Cat(const std::string& name);
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	void	makeSound() const ;
	// void	getType() const ;
	~Cat();
};

}
