#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class	Bureaucrat;

class PresidentialPardonForm : public Form
{
	public:

		PresidentialPardonForm(void); //default constructor
		PresidentialPardonForm(std::string target); //target constructor
		PresidentialPardonForm(PresidentialPardonForm const & copy); //copy constructor
		~PresidentialPardonForm(void); //destructor

		PresidentialPardonForm	&operator=(PresidentialPardonForm const & rhs); //assignement operator

		bool					execute(Bureaucrat const & executor) const;

	private:

		std::string			_target;

};

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif