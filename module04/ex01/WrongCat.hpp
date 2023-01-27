#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat(void); //default constructor
		WrongCat(WrongCat const & copy); //copy constructor
		WrongCat	&operator=(WrongCat const & rhs); //assignement operator
		~WrongCat(void); //destructor

		void makeSound(void) const;

};

#endif