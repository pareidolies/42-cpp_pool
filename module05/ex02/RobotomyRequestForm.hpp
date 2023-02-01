#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		RobotomyRequestForm(void); //default constructor
		RobotomyRequestForm(std::string const name, int gradeToSign, int gradeToExecute); //name and grade constructor
		RobotomyRequestForm(RobotomyRequestForm const & copy); //copy constructor
		~RobotomyRequestForm(void); //destructor

		RobotomyRequestForm	&operator=(RobotomyRequestForm const & rhs); //assignement operator

		std::string const 		getName(void) const;
		int 					getGradeToSign(void) const;
		int 					getGradeToExecute(void) const;

		bool					beSigned(Bureaucrat bureaucrat);

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

	private:

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif