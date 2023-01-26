#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:

		Cat(void); //default constructor
		Cat(Cat const & copy); //copy constructor
		Cat	&operator=(Cat const & rhs); //assignement operator
		~Cat(void); //destructor

		void makeSound(void);

};

#endif