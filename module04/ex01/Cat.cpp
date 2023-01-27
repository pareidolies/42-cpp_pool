#include "Cat.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Cat::Cat(void) : Animal()
{
    this->type = "Cat";
	brain = new Brain;
	std::cout << ANSI_BLUE << "Cat constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Cat::Cat(Cat const & copy)
{
	if (this == &copy)
		return ;
	this->brain = new Brain;
    *this = copy;
	std::cout << ANSI_YELLOW << "Cat copy constructor called" << ANSI_RESET << std::endl;
}

Cat	&Cat::operator=(Cat const & rhs)
{
	std::cout << ANSI_YELLOW << "Cat assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
	{
		this->brain = rhs.brain;
		this->type = rhs.type;
	}
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

Cat::~Cat(void)
{
	delete brain;
	std::cout << ANSI_BLUE << "Cat destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Cat::makeSound(void) const
{	
	std::cout << ANSI_RED << "Meow meow!" << ANSI_RESET << std::endl;
}

void	Cat::setIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

std::string	Cat::getIdea(int i)
{
	return(brain->getIdea(i));
}
