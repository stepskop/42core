#include "Point.hpp"

static Fixed side(Point p, Point v1, Point v2) {
	return (p.x() - v2.x()) * (v1.y() - v2.y()) - (v1.x() - v2.x()) * (p.y() - v2.y());
}

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed ab, bc, ca;
	ab = side(point, a, b);
	bc = side(point, b, c);
	ca = side(point, c, a);
	return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}
