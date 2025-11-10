#include "./Fixed.hpp"
#include <iostream>

int main( void ) {
	fixed::Fixed a;
	fixed::Fixed const b(10);
	fixed::Fixed const c(42.42f);
	fixed::Fixed const d(b);

	a = fixed::Fixed( 1234.4321f );

	std::cout << "a is " << a.toFloat() << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
