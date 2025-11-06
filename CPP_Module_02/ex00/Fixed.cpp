#include "./Fixed.hpp"
#include <iostream>

namespace fixed {

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const Fixed& toCopy) {
	std::cout << "Copy constructor called\n";
	_value = toCopy._value;
}

Fixed&	Fixed::operator=(const Fixed& toCopy) {
	std::cout << "Copy assignment operator called\n";
	if (this != &toCopy) {
		_value = toCopy._value;
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

}
