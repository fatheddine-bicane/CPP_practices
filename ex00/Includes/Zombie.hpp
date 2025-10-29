#pragma once

#include <string>

namespace zombieSpawn {

class Zombie {
private:
	std::string	_zombieName;

public:
	Zombie(std::string zombieName);
	void	announce(void);
	~Zombie(void);
};

}
