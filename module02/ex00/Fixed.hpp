#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RESET			"\x1b[0m"

class Fixed
{
	public:

		Fixed(void); //constructor
		Fixed(Fixed const & copy); //copy constructor called
		Fixed	&operator=(Fixed const & rhs); //copy assignment operator
		~Fixed(void); //destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		
		int					_fixedPointNbr;
		static const int	_fractBitsNbr = 8;

};


#endif