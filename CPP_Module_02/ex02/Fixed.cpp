#include "./Fixed.hpp"
#include <cmath>
#include <iostream>

namespace fixed {

const int Fixed::_fractionalBits = 8;

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs) {
	lhs << rhs.toFloat();
	return lhs;
}

// INFO: constructors
/*--------------------------------------------------------*/
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
	_value = roundf(value * 256);
}

Fixed::Fixed(const Fixed& toCopy) {
	std::cout << "Copy constructor called\n";
	_value = toCopy._value;
}
/*--------------------------------------------------------*/


// INFO: binary operators
/*--------------------------------------------------------*/
Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs) {
		_value = rhs._value;
	}
	return *this;
}

bool	Fixed::operator>(const Fixed& rhs) const {
	if (this->toFloat() > rhs.toFloat()) {
		return true;
	}
	return false;
}

bool	Fixed::operator<(const Fixed& rhs) const {
	return !(operator>(rhs));
}

bool	Fixed::operator>=(const Fixed& rhs) const {
	if (this->toFloat() >= rhs.toFloat()) {
		return true;
	}
	return false;
}

bool	Fixed::operator<=(const Fixed& rhs) const {
	if (this->toFloat() <= rhs.toFloat()) {
		return true;
	}
	return false;
}

bool	Fixed::operator==(const Fixed& rhs) const {
	if (this->toFloat() == rhs.toFloat()) {
		return true;
	}
	return false;
}

bool	Fixed::operator!=(const Fixed& rhs) const {
	return !(operator==(rhs));
}

Fixed	Fixed::operator+(const Fixed& rhs) {
	return Fixed(toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) {
	return Fixed(toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) {
	return Fixed(toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) {
	return Fixed(toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++() {
	float result = toFloat() + 1.0 / 256;
	_value = roundf(result * 256);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	float result = toFloat() - 1.0 / 256;
	_value = roundf(result * 256);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

/*--------------------------------------------------------*/



// INFO: member functions
/*--------------------------------------------------------*/
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
/*--------------------------------------------------------*/



// INFO: static functions
/*--------------------------------------------------------*/
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 <= fixed2) {
		return fixed1;
	}
	return fixed2;
}

Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 <= fixed2) {
		return (Fixed&)fixed1;
	}
	return (Fixed&)fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 >= fixed2) {
		return fixed1;
	}
	return fixed2;
}

Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 >= fixed2) {
		return (Fixed&)fixed1;
	}
	return (Fixed&)fixed2;
}

/*--------------------------------------------------------*/


// INFO: destructor
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

}
