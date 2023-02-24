#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void); //default constructor
        FragTrap(std::string const & name); //name constructor
		FragTrap(FragTrap const & copy); //copy constructor
		FragTrap	&operator=(FragTrap const & rhs); //copy assignment operator
		~FragTrap(void); //destructor

		void highFivesGuys(void);

};

#endif