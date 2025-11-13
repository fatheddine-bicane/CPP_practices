#pragma once

namespace fixed {

class Fixed {
private:
	int	_value;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed(const Fixed& toCopy);
	Fixed&	operator=(const Fixed& toCopy);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	~Fixed();
};

}
