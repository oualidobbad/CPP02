#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
		
	public:
		Point();
		Point(const float nb1, const float nb2);
		// Point(const Fixed f1, const Fixed f2);
		Point(const Point& point);
		Point& operator=(const Point& point);
		Fixed getX() const;
		Fixed getY() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);