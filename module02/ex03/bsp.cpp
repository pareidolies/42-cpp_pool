# include "Point.hpp"

//needs to check when point on a or b or c

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area1(point.area(a, b));
	Fixed area2(point.area(b, c));
	Fixed area3(point.area(c, a));

	if (area1 > 0 && area2 > 0 && area3 > 0)
		return (true);
    if (area1 < 0 && area2 < 0 && area3 < 0)
		return (true);
	return (false);
}