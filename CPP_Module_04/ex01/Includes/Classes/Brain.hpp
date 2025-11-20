#pragma once

#include <string>

namespace zoo {

class Brain {
private:
	std::string	_ideas[100];

public:
	Brain();
	Brain(std::string ideas[]);
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();
};

}
