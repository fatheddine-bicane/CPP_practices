#pragma once

#include "./WrongAnimal.hpp"

namespace zoo {

class WrongCat : public WrongAnimal {
private:
	std::string	_name;

public:
	WrongCat();
	WrongCat(const std::string& name);
	WrongCat(const WrongCat& other);
	WrongCat&	operator=(const WrongCat& other);
	void	makeSound() const ;
	~WrongCat();
};

}
