#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class Brain
{
	public:

		Brain(void); //default constructor
		Brain(Brain const & copy); //copy constructor
		Brain	&operator=(Brain const & rhs); //assignment operator
		virtual ~Brain(void); //destructor

		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i);

	private:

		std::string	ideas[100];

};

#endif
