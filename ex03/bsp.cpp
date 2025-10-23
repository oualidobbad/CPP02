#include "Point.hpp"

// (1 / 2) |[x1 (y2 – y3 ) + x2 (y3 – y1 ) + x3(y1 – y2)]|

Fixed areaOfTriangle(Point a, Point b, Point c)
{
	Fixed area;

	area = Fixed(0.5f) * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));

	if (area < 0)
		return area * Fixed(-1);
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed apb, bpc, apc, abc;
    
    abc = areaOfTriangle(a, b, c);
    if (abc == 0)
        return false;
    
    apb = areaOfTriangle(a, point, b);
    bpc = areaOfTriangle(b, point, c);
    apc = areaOfTriangle(a, point, c);
    
    Fixed sum = apb + bpc + apc;
	if (apb == 0 || bpc == 0 || apc == 0)
		return false;
    return (sum==abc);
}