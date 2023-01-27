#include "Brain.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Brain::Brain(void)
{
	std::cout << ANSI_BLUE << "Brain default constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Brain::Brain(Brain const & copy)
{
    *this = copy;
	std::cout << ANSI_YELLOW << "Copy constructor called" << ANSI_RESET << std::endl;
}

Brain	&Brain::operator=(Brain const & rhs)
{
	std::cout << ANSI_YELLOW << "Assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
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

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Please enter a number between 0 and 99" << std::endl;
		return ;
	}
	ideas[i] = idea;
}

std::string	Brain::getIdea(int i)
{
	if (i < 0 || i >= 100)
		return "Please enter a number between 0 and 99";
	return (ideas[i]);
}
