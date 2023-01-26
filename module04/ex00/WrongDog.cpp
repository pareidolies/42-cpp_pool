#include "WrongDog.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

WrongDog::WrongDog(void) : WrongAnimal()
{
    this->type = "WrongDog";
	std::cout << ANSI_BLUE << "WrongDog constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

WrongDog::WrongDog(WrongDog const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "WrongDog copy constructor called" << ANSI_RESET << std::endl;
}

WrongDog	&WrongDog::operator=(WrongDog const & rhs)
{
	std::cout << ANSI_YELLOW << "WrongDog assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

WrongDog::~WrongDog(void)
{
	std::cout << ANSI_BLUE << "WrongDog destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	WrongDog::makeSound(void) const
{	
	std::cout << ANSI_RED << "Woof woof!" << ANSI_RESET << std::endl;
}
