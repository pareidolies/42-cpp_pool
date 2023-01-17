#include "ClapTrap.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

ClapTrap::ClapTrap(void) : _name("Labradoodle") _hitPoints(10) _energyPoints(10) _attackDamage(0)
{
	std::cout << ANSI_BLUE << "Default constructor called for " << _name << ANSI_RESET << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name) _hitPoints(10) _energyPoints(10) _attackDamage(0)
{
	std::cout << ANSI_BLUE << "Name constructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

ClapTrap::ClapTrap(Fixed const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << ANSI_YELLOW << "Copy assignment operator called" << ANSI_RESET << std::endl;
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

ClapTrap::~ClapTrap(void)
{
	std::cout << ANSI_BLUE << "Destructor called for " << _name << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	ClapTrap::attack(const std::string& target)
{
	std::cout << ANSI_PURPLE << "ClapTrap"
	<< _name << "attacks" << _target << ", causing " << _attackDamage 
	<< "points of damage!"<< ANSI_RESET << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	this->_energyPoints--;
	std::cout << ANSI_RED << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << ANSI_GREEN << "ClapTrap " << _name << " recovers " << amount << " hit points!" << std::endl;
	return;
}
