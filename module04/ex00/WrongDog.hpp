#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:

		WrongDog(void); //default constructor
		WrongDog(WrongDog const & copy); //copy constructor
		WrongDog	&operator=(WrongDog const & rhs); //assignement operator
		~WrongDog(void); //destructor

		void makeSound(void) const;

};

#endif