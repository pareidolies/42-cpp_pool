#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class Animal
{
	public:

		Animal(void); //default constructor
		Animal(std::string const & name); //name constructor
		Animal(ClapTrap const & copy); //copy constructor
		Animal	&operator=(Animal const & rhs); //assignment operator
		~Animal(void); //destructor

		virtual void makeSound(void);

	protected:

		std::string			type;

};

#endif
