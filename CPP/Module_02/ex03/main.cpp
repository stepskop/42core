#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int main() {

	Point A(-10.5, -10.5);
	Point B(20.5, 20.5);
	Point C(-10, 20);

	Point target(-5, 5);
	std::cout << bsp(A, B, C, target) << std::endl;
}
