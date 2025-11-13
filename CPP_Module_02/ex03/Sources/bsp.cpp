#include "../Includes/bsp.hpp"
#include <cmath>

namespace Bsp {

static float	triangleArea(Point const p1, Point const p2, Point const p3) {
	float p1x = p1.getXCoordinate();
	float p1y = p1.getYCoordinate();
	float p2x = p2.getXCoordinate();
	float p2y = p2.getYCoordinate();
	float p3x = p3.getXCoordinate();
	float p3y = p3.getYCoordinate();

	float area = 0.5 * ((p1x - p2x) * (p1y - p3y) - (p1x - p3x) * (p1y - p2y));
	return fabs(area);
}

bool	bsp(Point const a, Point const b,
		    Point const c, Point const point) {

	const float triangleABC = triangleArea(a, b, c);
	fixed::Fixed	triangleABP = triangleArea(a, b, point);
	fixed::Fixed	triangleBCP = triangleArea(b, c, point);
	fixed::Fixed	triangleCPA = triangleArea(c, point, a);

	if (triangleABP == 0
		|| triangleBCP == 0
		|| triangleCPA == 0) {
		return false;
	}
	fixed::Fixed sum = triangleABP + triangleBCP + triangleCPA;
	bool result = (roundf(sum.toFloat()) == roundf(triangleABC)) ? true : false;
	return result;
}



// INFO: the slope methode

// static float	calculateSlope(Point const fenceStart,
// 					   Point const fenceEnd,
// 					   Point const point) {
// 	float	fenceStartX = fenceStart.getXCoordinate();
// 	float	fenceStartY = fenceStart.getYCoordinate();
// 	float	fenceEndX = fenceEnd.getXCoordinate();
// 	float	fenceEndY = fenceEnd.getYCoordinate();
// 	float	pointX = point.getXCoordinate();
// 	float	pointY = point.getYCoordinate();
//
// 	float	side = (fenceEndX - fenceStartX) * (pointY - fenceStartY)
// 					- (fenceEndY - fenceStartY) * (pointX - fenceStartX);
// 	return side;
// }
//
// bool	bsp(Point const a, Point const b,
// 		    Point const c, Point const point) {
//
// 	float sideA = calculateSlope(a, b, point);
// 	float sideB = calculateSlope(b, c, point);
// 	float sideC = calculateSlope(c, a, point);
//
// 	std::cout << "a: " << sideA << std::endl;
//
// 	// bool result = ((sideA > 0 && sideB > 0 && sideC > 0)
// 	// 	|| (sideA < 0 && sideB < 0 && sideC < 0)) ? true : false;
// 	// return result;
//
// 	if (sideA > 0 && sideB > 0 && sideC > 0) {
// 		return true;
// 	}
// 	if (sideA < 0 && sideB < 0 && sideC < 0) {
// 		return true;
// 	}
//
// 	return false;
// }

}
