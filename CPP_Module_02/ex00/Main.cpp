#include "./Fixed.hpp"
#include <iostream>

int	main () {
	fixed::Fixed	a;
	fixed::Fixed	b( a );
	fixed::Fixed	c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
