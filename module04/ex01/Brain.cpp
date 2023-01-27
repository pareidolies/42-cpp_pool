#include "Brain.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Brain::Brain(void) : type("Brain")
{
	std::cout << ANSI_BLUE << "Brain default constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Brain::Brain(Brain const & copy)
{
	if (this == &copy)
		return ;
    *this = copy;
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
}

Brain	&Brain::operator=(Brain const & rhs)
{
	std::cout << ANSI_YELLOW << "Assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

Brain::~Brain(void)
{
	std::cout << ANSI_BLUE << "Brain destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Brain::makeSound(void) const
{	
	std::cout << ANSI_RED << "Brain makes sound!" << ANSI_RESET << std::endl;
}

std::string	Brain::getType(void) const
{
	return(this->type);
}
