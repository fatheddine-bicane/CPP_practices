#include "../Includes/Classes/Point.hpp"

namespace Bsp {

Point::Point()
	: _x(0),
	  _y(0) {}

Point::Point(const float x, const float y)
	: _x(x),
	  _y(y) {}

Point::Point(const Point& other) {
	_x = other._x;
	_y = other._y;
}

Point&	Point::operator=(const Point& other) {
	if (this == &other) {
		return *this;
	}
	_x = other._x;
	_y = other._y;
	return *this;
}

float	Point::getXCoordinate() const {
	return _x.toFloat();
}

float	Point::getYCoordinate() const {
	return _y.toFloat();
}

Point::~Point() {}

}
