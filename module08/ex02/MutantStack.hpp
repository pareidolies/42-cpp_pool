#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

template <class T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack<T>() {}; //default constructor
		MutantStack<T>(MutantStack const & copy) : std::stack<T>(copy) {} //copy constructor
		~MutantStack<T>(void) {}; //destructor

		MutantStack	&operator=(MutantStack const & rhs) //assignement operator
		{
			if (this != &rhs)
				this = rhs; 
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}
		
		iterator end()
		{
			return this->c.end();
		}
};

#endif