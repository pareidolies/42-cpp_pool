#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class AAnimal
{
	public:

		AAnimal(void); //default constructor
		AAnimal(AAnimal const & copy); //copy constructor
		AAnimal	&operator=(AAnimal const & rhs); //assignment operator
		virtual ~AAnimal(void); //destructor

		virtual void makeSound(void) const = 0;
		std::string	getType(void) const;

	protected:

		std::string			type;

};

#endif
