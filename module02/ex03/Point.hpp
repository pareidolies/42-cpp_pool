#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
	public:

		Point(void);
		Point(const float x, const float y);
		Point(Point const & copy);
		Point &operator=(Point const & rhs);
		~Point(void);

		float	area(Point const & a, Point const & b) const;

	private:
		const Fixed _x;
		const Fixed _y;
        
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif