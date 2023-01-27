#include "AAnimal.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << ANSI_BLUE << "AAnimal default constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

AAnimal::AAnimal(AAnimal const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << ANSI_YELLOW << "Assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

AAnimal::~AAnimal(void)
{
	std::cout << ANSI_BLUE << "AAnimal destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

std::string	AAnimal::getType(void) const
{
	return(this->type);
}
