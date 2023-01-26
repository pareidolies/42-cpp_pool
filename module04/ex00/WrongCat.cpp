#include "WrongCat.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

WrongCat::WrongCat(void) : WrongAnimal()
{
    this->type = "WrongCat";
	std::cout << ANSI_BLUE << "WrongCat constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

WrongCat::WrongCat(WrongCat const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "WrongCat copy constructor called" << ANSI_RESET << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << ANSI_YELLOW << "WrongCat assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

WrongCat::~WrongCat(void)
{
	std::cout << ANSI_BLUE << "WrongCat destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	WrongCat::makeSound(void) const
{	
	std::cout << ANSI_RED << "Meow meow!" << ANSI_RESET << std::endl;
}
