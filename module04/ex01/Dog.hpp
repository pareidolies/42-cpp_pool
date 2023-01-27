#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:

		Dog(void); //default constructor
		Dog(Dog const & copy); //copy constructor
		Dog	&operator=(Dog const & rhs); //assignement operator
		~Dog(void); //destructor

		void 		makeSound(void) const;
		Brain 		*getBrain(void) const;

	private:

		Brain	*brain;

};

#endif