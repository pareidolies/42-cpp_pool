#include "Dog.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Dog::Dog(void) : Animal()
{
    this->type = "Dog";
	std::cout << ANSI_BLUE << "Dog constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Dog::Dog(Dog const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Dog copy constructor called" << ANSI_RESET << std::endl;
}

Dog	&Dog::operator=(Dog const & rhs)
{
	std::cout << ANSI_YELLOW << "Dog assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

Dog::~Dog(void)
{
	std::cout << ANSI_BLUE << "Dog destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Dog::makeSound(void) const
{	
	std::cout << ANSI_RED << "Woof woof!" << ANSI_RESET << std::endl;
}
