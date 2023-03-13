#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iterator>
# include <vector>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class Span
{
	public:

		class	CannotAddElement : public std::exception
		{
			public:

				virtual char const *	what() const throw();

		};

		class	CannotFindSpan : public std::exception
		{
			public:

				virtual char const *	what() const throw();

		};

		Span(void); //default constructor
		Span(unsigned int n); //unsigned int constructor
		Span(Span const & copy); //copy constructor
		~Span(void); //destructor

		Span	&operator=(Span const & rhs); //assignement operator

		void			addNumber(int nbr);
		unsigned int	longestSpan(void) const;
		unsigned int	shortestSpan(void) const;
		void			print(void) const;
		void			fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void			printSpan(void);

		std::vector<int>	&getVector(void);
		unsigned int		getSize(void);

	private:

		unsigned int 		_sizeMax;
		std::vector<int>	_vector;
};

#endif