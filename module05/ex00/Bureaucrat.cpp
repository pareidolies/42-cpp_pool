#include "Bureaucrat.hpp"
#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Bureaucrat::Bureaucrat(void)
{
    this->type = "Bureaucrat";
	brain = new Brain;
	std::cout << ANSI_BLUE << "Bureaucrat constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : AAnimal(), brain(NULL)
{
	*this = copy;
	std::cout << ANSI_YELLOW << "Bureaucrat copy constructor called" << ANSI_RESET << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << ANSI_YELLOW << "Bureaucrat assignment operator called" << ANSI_RESET << std::endl;
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

Bureaucrat::~Bureaucrat(void)
{
	delete (this->brain);
	std::cout << ANSI_BLUE << "Bureaucrat destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Bureaucrat::makeSound(void) const
{	
	std::cout << ANSI_RED << "Woof woof!" << ANSI_RESET << std::endl;
}

Brain *Bureaucrat::getBrain() const
{
	return (this->brain);
}
