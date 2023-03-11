#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <cmath>

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

		void			addNumber(int i);
		unsigned int	longestSpan(void) const;
		unsigned int	shortestSpan(void) const;
		void			print(void) const;

		template <typename T>
		void	fillSpan(typename T::const_iterator const & a, typename T::const_iterator const & b)
		{
			size_t	distance;

			distance = static_cast<size_t>(std::abs(std::distance(a, b)));
			if (distance > _size)
				throw(TooManyNumbers());
			else if (distance)
			{
				_list.insert(_list.end(), a, b); 
				_curr_size += distance;
			}
		}

	private:

		unsigned int _size;
		std::vector<int> _vector;
};

std::ostream &	operator<<(std::ostream & o, Span const & rhs);

#endif