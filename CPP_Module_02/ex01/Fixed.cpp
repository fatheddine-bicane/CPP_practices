#include "./Fixed.hpp"
#include <cmath>
#include <iostream>

namespace fixed {

const int Fixed::_fractionalBits = 8;

std::ostream&	operator<<(std::ostream& output, const Fixed& fixed) {
	output << fixed.toFloat();
	return output;
}

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	_value = value * 256;
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

float	Fixed::toFloat(void) const {
	// return (_value >> 8);
	return ((float)_value / 256.0);
}

int	Fixed::toInt(void) const {
	return (roundf(toFloat()));
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
