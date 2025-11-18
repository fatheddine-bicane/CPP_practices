#include "../Includes/Classes/Brain.hpp"
#include <iostream>

namespace zoo {

Brain::Brain() {
	std::cout << "Brain default constructor called!\n";
}

Brain::Brain(std::string ideas[]) {
	std::cout << "Brain parameterized constructor called!\n";
	for (int i = 0; i < 100; i++) {
		_ideas[i] = ideas[i];
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called!\n";
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& other) {
	if (this == &other) {
		return *this;
	}
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called!\n";
}

}
