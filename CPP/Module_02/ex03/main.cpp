#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int main() {
		{
			Point A(-10.5, -10.5);
			Point B(20.5, 20.5);
			Point C(-10, 20);

			Point target(-5, 5);
			std::cout << bsp(A, B, C, target) << std::endl;
		};
		{
		Point	a(0, 0);
		Point	b(10, 0);
		Point	c(0, 10);
		Point	p1(0, 0);
		Point	p2(10.1, 0);
		Point	p3(0, 10);
		Point	p4(3, 3);
		Point	p5(5.5, 5.5);
		Point	p6(5, 5);

		std::cout << "p1 in triangle:\t\t" << bsp(a,b,c,p1) << std::endl;

		std::cout << "p2 in triangle:\t\t" << bsp(a,b,c,p2) << std::endl;

		std::cout << "p3 in triangle:\t\t" << bsp(a,b,c,p3) << std::endl;

		std::cout << "p4 in triangle:\t\t" << bsp(a,b,c,p4) << std::endl;

		std::cout << "p5 in triangle:\t\t" << bsp(a,b,c,p5) << std::endl;

		std::cout << "p6 in triangle:\t\t" << bsp(a,b,c,p6) << std::endl;

		return 0;
	}

}
//https://planetcalc.com/8108/
