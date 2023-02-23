#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNbr(0)
{
	std::cout << ANSI_YELLOW << "Default constructor called" << ANSI_RESET << std::endl;
}

Fixed::Fixed(int const nbr) : _fixedPointNbr(nbr * (1 << Fixed::_fractBitsNbr))
{
	//std::cout << ANSI_YELLOW << this->_fixedPointNbr << ANSI_RESET << std::endl;
	std::cout << ANSI_BLUE << "Int constructor called" << ANSI_RESET << std::endl;
}

Fixed::Fixed(float const nbr) : _fixedPointNbr(roundf(nbr * (1 << Fixed::_fractBitsNbr))) 
{
	//std::cout << ANSI_YELLOW << this->_fixedPointNbr << ANSI_RESET << std::endl;
	std::cout << ANSI_BLUE << "Float constructor called" << ANSI_RESET << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
    this->_fixedPointNbr = copy.getRawBits();
	//std::cout << ANSI_YELLOW << this->_fixedPointNbr << ANSI_RESET << std::endl;
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << ANSI_YELLOW << "Copy assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_fixedPointNbr = rhs.getRawBits();
	//std::cout << ANSI_YELLOW << this->_fixedPointNbr << ANSI_RESET << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & out, Fixed const & copy) {
	out << copy.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << ANSI_YELLOW << "Destructor called" << ANSI_RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << ANSI_PURPLE << "GetRawBits member function called" << ANSI_RESET << std::endl;
	return (this->_fixedPointNbr);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << ANSI_PURPLE << "SetRawBits member function called" << ANSI_RESET << std::endl;
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
