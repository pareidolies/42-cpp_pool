#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <time.h>
# include <cstdlib>
# include <exception>
# include <unistd.h>

class Base
{
	public:

		virtual ~Base(void); //destructor

		Base *	generate(void);
		void	identify(Base *ptr);
		void	identify(Base &ptr);
};

#endif