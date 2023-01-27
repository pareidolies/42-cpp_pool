#include "WrongAnimal.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << ANSI_BLUE << "WrongAnimal default constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

WrongAnimal::WrongAnimal(WrongAnimal const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << ANSI_YELLOW << "Assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

WrongAnimal::~WrongAnimal(void)
{
	std::cout << ANSI_BLUE << "WrongAnimal destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	WrongAnimal::makeSound(void) const
{	
	std::cout << ANSI_RED << "WrongAnimal makes sound!" << ANSI_RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return(this->type);
}
