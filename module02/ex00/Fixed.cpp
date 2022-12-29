#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNbr(0)
{
	std::cout << ANSI_YELLOW << "Default constructor called" << ANSI_RESET << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
    this->_fixedPointNbr = copy.getRawBits();
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << ANSI_YELLOW << "Copy assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_fixedPointNbr = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << ANSI_YELLOW << "Destructor called" << ANSI_RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << ANSI_PURPLE << "getRawBits member function called" << ANSI_RESET << std::endl;
	return (this->_fixedPointNbr);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << ANSI_PURPLE << "setRawBits member function called" << ANSI_RESET << std::endl;
	this->_fixedPointNbr = raw;
}
