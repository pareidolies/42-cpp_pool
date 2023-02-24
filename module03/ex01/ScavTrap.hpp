#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void); //default constructor
        ScavTrap(std::string const & name); //name constructor
		ScavTrap(ScavTrap const & copy); //copy constructor
		ScavTrap	&operator=(ScavTrap const & rhs); //copy assignment operator
		~ScavTrap(void); //destructor

		void attack(const std::string& target);
		void guardGate(void);

};

#endif