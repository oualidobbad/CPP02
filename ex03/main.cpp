#include "Point.hpp"

int main (){

	Point a(0, 0);
	Point b(10, 0);
	Point c(10, 5);
	Point point(2, 1);

	if (bsp(a,b, c, point) == false)
		std::cout << "point(" <<point.getX() << ", "<< point.getY() << ") outside" << std::endl;
	else
		std::cout << "point(" <<point.getX() << ", "<< point.getY() << ") inside" << std::endl;
}
