#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class Convert
{
	public:

		Convert(void); //default constructor
		Convert(std::string value); //value constructor
		Convert(Convert const & copy); //copy constructor
		~Convert(void); //destructor

		Convert	&operator=(Convert const & rhs); //assignement operator

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

std::ostream &	operator<<(std::ostream & o, Convert const & rhs);

#endif