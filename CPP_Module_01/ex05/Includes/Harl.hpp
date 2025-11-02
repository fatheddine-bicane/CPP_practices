#pragma once

#include <string>
#include <iostream>
#include "./colors.hpp"

namespace harl {

class Harl {

	typedef void(Harl::*complainLevel)(void);

public:
	void complain(std::string level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	unknownLevel(void);
	void	defineLevel(std::string, complainLevel&);
	
};

}
