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
    *this = copy;
	std::cout << ANSI_YELLOW << "Cat copy constructor called" << ANSI_RESET << std::endl;
}

Cat	&Cat::operator=(Cat const & rhs)
{
	std::cout << ANSI_YELLOW << "Cat assignment operator called" << ANSI_RESET << std::endl;
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

Cat::~Cat(void)
{
	delete (this->brain);
	std::cout << ANSI_BLUE << "Cat destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Cat::makeSound(void) const
{	
	std::cout << ANSI_RED << "Meow meow!" << ANSI_RESET << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}
