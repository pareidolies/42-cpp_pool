#include "ScavTrap.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

ScavTrap::ScavTrap(void) : _name("Labradoodle"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << ANSI_BLUE << "ScavTrap default constructor called for " << _name << ANSI_RESET << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << ANSI_BLUE << "ScavTrap name constructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

ScavTrap::ScavTrap(ScavTrap const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "ScavTrap copy constructor called" << ANSI_RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << ANSI_YELLOW << "ScavTrap copy assignment operator called" << ANSI_RESET << std::endl;
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

ScavTrap::~ScavTrap(void)
{
	std::cout << ANSI_BLUE << "ScavTrap destructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << ANSI_RED << "ScavTrap "
			<< _name << " has no more energy, and so cannot attack" << ANSI_RESET << std::endl;
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << ANSI_RED << "ScavTrap "
			<< _name << " is dead, and so cannot attack" << ANSI_RESET << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << ANSI_PURPLE << "ScavTrap "
	<< _name << " attacks " << target << ", causing " << _attackDamage
	<< " points of damage!"<< ANSI_RESET << std::endl;
	return;
}

void ScavTrap::guardGate(void)
{
    std::cout << ANSI_GREEN << "ScavTrap " << _name << " in gate keeper mode!" << ANSI_RESET << std::endl;
}