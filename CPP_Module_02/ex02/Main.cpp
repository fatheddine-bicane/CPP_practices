#include "./Fixed.hpp"
#include <iostream>

int main( void ) {
	fixed::Fixed a;
	fixed::Fixed const b( fixed::Fixed( 5.05f ) * fixed::Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << fixed::Fixed::max( a, b ) << std::endl;
	return 0;
}
