#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RESET			"\x1b[0m"

class Fixed
{
	public:

		Fixed(void); //constructeur
		Fixed(Fixed const & copy); // constructeur de recopie
		Fixed	&operator=(Fixed const & rhs); // surcharge de l'opérateur d'affectation
		~Fixed(void); //destructeur

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		
		int					_fixedPointNbr;
		static const int	_fractBitsNbr = 8;

};


#endif