#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class	Form;

class Bureaucrat
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

		Bureaucrat(void); //default constructor
		Bureaucrat(std::string const name, int grade); //name and grade constructor
		Bureaucrat(Bureaucrat const & copy); //copy constructor
		~Bureaucrat(void); //destructor

		Bureaucrat	&operator=(Bureaucrat const & rhs); //assignement operator

		std::string const 		getName(void) const;
		int 					getGrade(void) const;

		void					upgrade(void);
		void					downgrade(void);

		void					signForm(Form & form);
		void					executeForm(Form const & form);

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

	private:

		std::string const	_name;
		int					_grade;

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif