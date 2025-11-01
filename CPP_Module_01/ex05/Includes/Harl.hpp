#pragma once

#include <string>
#include <iostream>
#define BLUE  "\001\033[34m\002"
#define RESET "\001\033[0m\002"
#define RED   "\001\033[31m\002"
#define PURPLE "\001\033[35m\002"

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
