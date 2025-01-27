#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &src);
		~Point(void);
		Point &operator = (const Point &src);

		Fixed x(void) const;
		Fixed y(void) const;
};
#endif
