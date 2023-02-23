#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>
# include <cmath>
# include <string>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RESET			"\x1b[0m"

class Fixed
{
	public:

		Fixed(void); //default constructor
		Fixed(int const nbr); //int constructor
		Fixed(float const nbr); //float constructor

		Fixed(Fixed const & copy); //copy constructor
		Fixed	&operator=(Fixed const & rhs); //copy assignment operator
		~Fixed(void); //destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		
		int					_fixedPointNbr;
		static const int	_fractBitsNbr = 8;

};

std::ostream &operator<<(std::ostream & out, Fixed const & copy); //surcharge de l'opérateur d'insertion

#endif