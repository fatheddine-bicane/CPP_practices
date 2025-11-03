#pragma once

#include <string>

namespace zombieHorde {

class Zombie {
private:
	std::string	_zombieName;

public:
	Zombie();
	void	announce();
	~Zombie(void);
};

}
