#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "Form.hpp"
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class	Bureaucrat;

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm(void); //default constructor
		RobotomyRequestForm(std::string target); //target constructor
		RobotomyRequestForm(RobotomyRequestForm const & copy); //copy constructor
		~RobotomyRequestForm(void); //destructor

		RobotomyRequestForm	&operator=(RobotomyRequestForm const & rhs); //assignement operator

		bool					execute(Bureaucrat const & executor) const;

	private:

		std::string			_target;

};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif