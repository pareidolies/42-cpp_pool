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

Dog::Dog(Dog const & copy) : Animal(copy.type), brain(new Brain(*copy.brain))
{
	std::cout << ANSI_YELLOW << "Dog copy constructor called" << ANSI_RESET << std::endl;
}

Dog	&Dog::operator=(Dog const & rhs)
{
	std::cout << ANSI_YELLOW << "Dog assignment operator called" << ANSI_RESET << std::endl;
	if (this->brain)
		delete (this->brain);
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain->setIdea(i, rhs.brain->getIdea(i));
	this->type = rhs.type;	
	return (*this);
}

/******************************************************************************
*                               DESTRUCTOR                                    *
******************************************************************************/

Dog::~Dog(void)
{
	delete (this->brain);
	std::cout << ANSI_BLUE << "Dog destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Dog::makeSound(void) const
{	
	std::cout << ANSI_RED << "Woof woof!" << ANSI_RESET << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}
