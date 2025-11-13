#include "../Includes/bsp.hpp"
#include <iostream>

int main( void ) {

	Bsp::Point a(1.0f, 1.0f);
	Bsp::Point b(2.0f, 3.0f);
	Bsp::Point c(3.0f, 1.0f);

	Bsp::Point point(2.0f, 2.0f);
	bool isInside = Bsp::bsp(a, b, c, point);
	if (isInside)
		std::cout << "True, the point is inside the triangle ABC!\n";
	else
		std::cout << "False, the point is not inside the triangle ABC!\n";

}
