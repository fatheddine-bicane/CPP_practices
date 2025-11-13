#pragma once

#include "./Fixed.hpp"

namespace Bsp {

class Point {
private:
	fixed::Fixed	_x;
	fixed::Fixed	_y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point&	operator=(const Point& other);
	float	getXCoordinate() const;
	float	getYCoordinate() const;
	~Point();
};

}
