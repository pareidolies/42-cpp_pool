# include "DiamondTrap.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

DiamondTrap::DiamondTrap(void) : ClapTrap("Labradoodle" + "_clap_name"), FragTrap("Labradoodle"), ScavTrap("Labradoodle")
{
    this->_name = "Labradoodle";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
	std::cout << ANSI_BLUE << "DiamondTrap default constructor called for " << _name << ANSI_RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
	std::cout << ANSI_BLUE << "DiamondTrap name constructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

DiamondTrap::DiamondTrap(DiamondTrap const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "DiamondTrap copy constructor called" << ANSI_RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << ANSI_YELLOW << "DiamondTrap copy assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

DiamondTrap::~DiamondTrap(void)
{
	std::cout << ANSI_BLUE << "DiamondTrap destructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void DiamondTrap::whoAmI(void)
{
    std::cout << ANSI_GREEN << "I am DiamondTrap " << _name << "and my ClapTrap is "
		<< ClapTrap::_name << ANSI_RESET << std::endl;
}
