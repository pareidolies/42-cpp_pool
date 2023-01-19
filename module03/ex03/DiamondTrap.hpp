#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
	public:

		DiamondTrap(void); //default constructor
        DiamondTrap(std::string const & name); //name constructor
		DiamondTrap(DiamondTrap const & copy); // constructeur de recopie
		DiamondTrap	&operator=(DiamondTrap const & rhs); // surcharge de l'opérateur d'affectation
		~DiamondTrap(void); //destructeur

		using ScavTrap::attack;

		void	whoAmI(void);

	private:

		std::string	_name;

};

#endif