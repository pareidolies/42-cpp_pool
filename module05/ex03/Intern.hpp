#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class Intern
{
	public:

		Intern(void); //default constructor
		Intern(Intern const & copy); //copy constructor
		~Intern(void); //destructor

		Intern	&operator=(Intern const & rhs); //assignement operator

		AForm		*makeForm(std::string form, std::string target);
		AForm		*makeShrubberyCreationForm(std::string target) const;
		AForm		*makeRobotomyRequestForm(std::string target) const;
		AForm		*makePresidentialPardonForm(std::string target) const;

	private:

};

std::ostream &	operator<<(std::ostream & o, Intern const & rhs);

#endif