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
		DiamondTrap(DiamondTrap const & copy); //copy constructor
		DiamondTrap	&operator=(DiamondTrap const & rhs); //copy assignment operator
		~DiamondTrap(void); //destructor

		using ScavTrap::attack;

		void	whoAmI(void);

	private:

		std::string	_name;

};

#endif