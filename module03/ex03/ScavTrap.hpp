#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void); //default constructor
        ScavTrap(std::string const & name); //name constructor
		ScavTrap(ScavTrap const & copy); // constructeur de recopie
		ScavTrap	&operator=(ScavTrap const & rhs); // surcharge de l'opérateur d'affectation
		~ScavTrap(void); //destructeur

		void attack(const std::string& target);
		void guardGate(void);

};

#endif