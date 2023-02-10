# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <unistd.h>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon Form", 25, 5)
{
	this->_target = "Prisoner";
	std::cout << ANSI_BLUE << "Default Presidential Pardon Form constructor called" << ANSI_RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
	std::cout << ANSI_BLUE << "Target Presidential Pardon Form constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : Form(copy)
{
	*this = copy;
	std::cout << ANSI_YELLOW << "Presidential Pardon Form copy constructor called" << ANSI_RESET << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << ANSI_YELLOW << "Presidential Pardon Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	Form::operator=(rhs);
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << ANSI_BLUE << "Presidential Pardon Form destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw (GradeTooLowException());
		return (false);
	}
	else if (this->getStatus() == true)
	{
		std::cout << _target << " has been pardonned by the president Zaphod Beeblebrox" << std::endl;
		usleep(1000000);
		return (true);
	}
	else
	{
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because form has not been signed yet" << std::endl;
		return (false);
	}
}
