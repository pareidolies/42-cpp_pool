#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void); //default constructor
        FragTrap(std::string const & name); //name constructor
		FragTrap(FragTrap const & copy); // constructeur de recopie
		FragTrap	&operator=(FragTrap const & rhs); // surcharge de l'opérateur d'affectation
		~FragTrap(void); //destructeur

		void highFivesGuys(void);

};

#endif