#include "Dog.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Dog::Dog(void) : Animal()
{
    this->type = "Dog";
	brain = new Brain;
	std::cout << ANSI_BLUE << "Dog constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Dog::Dog(Dog const & copy)
{
	this->brain = new Brain;
	*this = copy;
	std::cout << ANSI_YELLOW << "Dog copy constructor called" << ANSI_RESET << std::endl;
}

Dog	&Dog::operator=(Dog const & rhs)
{
	std::cout << ANSI_YELLOW << "Dog assignment operator called" << ANSI_RESET << std::endl;
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

Dog::~Dog(void)
{
	delete brain;
	std::cout << ANSI_BLUE << "Dog destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Dog::makeSound(void) const
{	
	std::cout << ANSI_RED << "Woof woof!" << ANSI_RESET << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i)
{
	return(brain->getIdea(i));
}
