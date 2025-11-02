#pragma once

#include <string>
#include <iostream>
#include "./colors.hpp"

namespace harlFilter {

class Harl {

	typedef enum {
		DEBUG, INFO, WARNING, ERROR, UNKNOWN
	} Level;

public:
	void complain(std::string level);

private:
	Level	_level;
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	unknownLevel(void);
	void	defineLevel(std::string level);
	void	startComplaining();
};

}
