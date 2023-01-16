# include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{

}

Point::Point(float const x, float const y) : _x(x), _y(y)
{

}

Point::Point(Point const & copy) : _x(copy._x), _y(copy._y)
{

}

Point &	Point::operator=(Point const & rhs)
{
	(void) rhs;
	std::cout << "Error: assignement operation impossible, all attributes are constants.\n";
	return (*this);
}

Point::~Point(void)
{

}

float	Point::area(Point const & a, Point const & b) const
{
	float area = (a._x.toFloat() - this->_x.toFloat()) * (b._y.toFloat() - this->_y.toFloat()) \
        - (a._y.toFloat() - this->_y.toFloat()) * (b._x.toFloat() - this->_x.toFloat());
	return (area);
}
