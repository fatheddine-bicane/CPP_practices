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
	Fixed&	operator=(const Fixed& rhs);
	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	Fixed	operator+(const Fixed& rhs);
	Fixed	operator-(const Fixed& rhs);
	Fixed	operator*(const Fixed& rhs);
	Fixed	operator/(const Fixed& rhs);
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	float	toFloat(void) const ;
	int		toInt(void) const ;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	~Fixed();
};

std::ostream&	operator<<(std::ostream& output, const Fixed& fixed);

}
