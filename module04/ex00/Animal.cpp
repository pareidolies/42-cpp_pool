#include "Animal.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Animal::Animal(void) : type("Animal")
{
	std::cout << ANSI_BLUE << "Animal default constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Animal::Animal(Animal const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Animal copy constructor called" << ANSI_RESET << std::endl;
}

Animal	&Animal::operator=(Animal const & rhs)
{
	std::cout << ANSI_YELLOW << "Animal assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

Animal::~Animal(void)
{
	std::cout << ANSI_BLUE << "Animal destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Animal::makeSound(void) const
{	
	std::cout << ANSI_RED << "Animal makes sound!" << ANSI_RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return(this->type);
}
