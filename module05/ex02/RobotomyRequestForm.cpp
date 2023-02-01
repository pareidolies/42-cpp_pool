# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdlib.h>
# include <time.h> 

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request Form", 25, 5)
{
	this->_target = "President";
	std::cout << ANSI_BLUE << "Default Robotomy Request Form constructor called" << ANSI_RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 25, 5)
{
	this->_target = target;
	std::cout << ANSI_BLUE << "Target Robotomy Request Form constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : Form(copy)
{
	*this = copy;
	std::cout << ANSI_YELLOW << "Robotomy Request Form copy constructor called" << ANSI_RESET << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << ANSI_YELLOW << "Robotomy Request Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	Form::operator=(rhs);
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << ANSI_BLUE << "Robotomy Request Form destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	result;

	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw (GradeTooLowException());
		return (false);
	}
	else if (this->getStatus() == true)
	{
		srand (time(NULL));
		result = rand() % 2;
		std::cout << "BZZZZZZZZZ RRRRRRRRR" << std::endl;
		if (result)
			std::cout << _target << " has been robotomized" << std::endl;
		else 
			std::cout << _target << " has not been robotomized" << std::endl;
		return (true);
	}
	else
	{
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because form has not been signed yet" << std::endl;
		return (false);
	}
}
