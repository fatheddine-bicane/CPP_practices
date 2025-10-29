#pragma once

#include <string>

namespace violence {

class Weapon {
private:
	std::string _type;

public:
	Weapon(std::string type);
	const std::string& getType();
	void	setType(std::string type);
};

}
