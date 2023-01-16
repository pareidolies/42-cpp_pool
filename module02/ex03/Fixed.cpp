#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNbr(0)
{
}

Fixed::Fixed(int const nbr) : _fixedPointNbr(nbr * (1 << Fixed::_fractBitsNbr))
{
}

Fixed::Fixed(float const nbr) : _fixedPointNbr(roundf(nbr * (1 << Fixed::_fractBitsNbr))) 
{
}

Fixed::Fixed(Fixed const & copy)
{
    this->_fixedPointNbr = copy.getRawBits();
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixedPointNbr = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & out, Fixed const & copy) {
	out << copy.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointNbr);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixedPointNbr = raw;
}

float Fixed::toFloat(void) const
{
	return ((float) this->_fixedPointNbr / (float) (1 << Fixed::_fractBitsNbr));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointNbr / (1 << Fixed::_fractBitsNbr));
}

bool Fixed::operator<(const Fixed& rhs)
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>(const Fixed& rhs)
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<=(const Fixed& rhs)
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator>=(const Fixed& rhs)
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator==(const Fixed& rhs)
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(const Fixed& rhs)
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs)
{	
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->_fixedPointNbr++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_fixedPointNbr--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixedPointNbr++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixedPointNbr--;
	return (tmp);
}

Fixed Fixed::min(const Fixed & a, const Fixed & b)
{
	if ((Fixed)a < (Fixed)b)
		return (a);
	return (b);
}

Fixed Fixed::max(const Fixed & a, const Fixed & b)
{
	if ((Fixed)a > (Fixed)b)
		return (a);
	return (b);
}

Fixed Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}
