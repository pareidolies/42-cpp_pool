#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class ScalarConverter
{
	public:

		ScalarConverter(void); //default constructor
		ScalarConverter(ScalarConverter const & copy); //copy constructor
		~ScalarConverter(void); //destructor

		ScalarConverter	&operator=(ScalarConverter const & rhs); //assignement operator

		void	convert(std::string value);
		bool	checkValue(std::string value);
		void	convertValue(std::string value);
		void	printAll(std::ostream &stream) const;

	private:

		std::string			_value;
		bool				_isNan;
		bool				_isExtreme;
		bool				_isChar;
		float				_float;
		int					_int;
		char				_char;
		double				_double;

};

std::ostream &	operator<<(std::ostream & o, ScalarConverter const & rhs);

#endif