#include "Animal.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Animal::Animal(void) : type("Animal")
{
	std::cout << ANSI_BLUE << "Animal default constructor called" << ANSI_RESET << std::endl;
}

Animal::Animal(std::string const & type) : type(type)
{
	std::cout << ANSI_BLUE << "Animal name constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Animal::Animal(Animal const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
}

Animal	&Animal::operator=(Animal const & rhs)
{
	std::cout << ANSI_YELLOW << "Assignment operator called" << ANSI_RESET << std::endl;
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

void	makeSound(void);
{	
	std::cout << ANSI_RED << "Animal makes sound!" << ANSI_RESET << std::endl;
}
