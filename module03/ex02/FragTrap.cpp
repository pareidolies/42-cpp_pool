#include "FragTrap.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

FragTrap::FragTrap(void) : ClapTrap()
{
    this->_name = "Anonymous";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
	std::cout << ANSI_BLUE << "FragTrap default constructor called for " << _name << ANSI_RESET << std::endl;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
	std::cout << ANSI_BLUE << "FragTrap name constructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap(copy._name)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "FragTrap copy constructor called" << ANSI_RESET << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << ANSI_YELLOW << "FragTrap copy assignment operator called" << ANSI_RESET << std::endl;
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

FragTrap::~FragTrap(void)
{
	std::cout << ANSI_BLUE << "FragTrap destructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << ANSI_RED << "FragTrap "
			<< _name << " has no more energy, and so cannot enter gate keeper mode" << ANSI_RESET << std::endl;
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << ANSI_RED << "FragTrap "
			<< _name << " is dead, and so cannot enter gate keeper mode" << ANSI_RESET << std::endl;
		return;
	}
    std::cout << ANSI_GREEN << "High five guys!" << ANSI_RESET << std::endl;
}