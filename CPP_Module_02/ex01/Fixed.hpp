#pragma once

#include <ostream>

namespace fixed {


class Fixed {
private:
	int					_value;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& toCopy);
	Fixed&	operator=(const Fixed& toCopy);
	float	toFloat(void) const ;
	int		toInt(void) const ;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	~Fixed();
};

std::ostream&	operator<<(std::ostream& output, const Fixed& fixed);

}
