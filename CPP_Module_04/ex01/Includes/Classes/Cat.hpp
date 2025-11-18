#pragma once

#include "./Animal.hpp"
#include "./Brain.hpp"

namespace zoo {

class Cat : public Animal {
private:
	std::string	_name;
	Brain*		_brain;

public:
	Cat();
	Cat(const std::string& name);
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	void	makeSound() const ;
	~Cat();
};

}
