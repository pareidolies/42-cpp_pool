#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <time.h>
# include <cstdlib>
# include <exception>
# include <unistd.h>

Base *	generate(void);
void	identify(Base *ptr);
void	identify(Base &ptr);

class Base
{
	public:

		virtual ~Base(void); //destructor

};

#endif