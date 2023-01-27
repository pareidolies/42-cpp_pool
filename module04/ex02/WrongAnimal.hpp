#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class WrongAnimal
{
	public:

		WrongAnimal(void); //default constructor
		WrongAnimal(WrongAnimal const & copy); //copy constructor
		WrongAnimal	&operator=(WrongAnimal const & rhs); //assignment operator
		virtual ~WrongAnimal(void); //destructor

		void makeSound(void) const;
		std::string	getType(void) const;

	protected:

		std::string			type;

};

#endif
