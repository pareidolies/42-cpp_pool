#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <stack>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class PmergeMe
{
	public:

		class WrongOrderException : public std::exception 
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		class WrongCharException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char * what(void) const throw(); 
		};

		PmergeMe(void);
		PmergeMe(const std::string &input);
		PmergeMe(PmergeMe const & copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const & rhs);

		double		compute(void);
		bool		isDigit(char c);
		bool		isOperator(char c);

	private:

		std::string				_input;
		std::stack<int> 		_stack;;
};

#endif