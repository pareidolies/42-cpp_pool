#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

		void					incrementGrade(void);
		void					decrementGrade(void);

		static unsigned int const	highestGrade = 1;
		static unsigned int const	lowestGrade = 150;

	private:

		std::string const	_name;
		int					_grade;

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif