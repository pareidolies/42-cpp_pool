# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdlib.h>
# include <time.h> 
# include <unistd.h>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45)
{
	this->_target = "President";
	//std::cout << ANSI_BLUE << "Default Robotomy Request Form constructor called" << ANSI_RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	this->_target = target;
	//std::cout << ANSI_BLUE << "Target Robotomy Request Form constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm(copy)
{
	*this = copy;
	//std::cout << ANSI_YELLOW << "Robotomy Request Form copy constructor called" << ANSI_RESET << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	//std::cout << ANSI_YELLOW << "Robotomy Request Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	AForm::operator=(rhs);
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << ANSI_BLUE << "Robotomy Request Form destructor called" << ANSI_RESET << std::endl;
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
		std::cout << ANSI_YELLOW << "BZZZZZZZZZ RRRRRRRRR" << ANSI_RESET << std::endl;
		usleep(1000000);
		if (result)
		{
			std::cout << ANSI_YELLOW << _target << " has been robotomized!" << ANSI_RESET << std::endl;
			usleep(1000000);
		}
		else 
		{
			std::cout << ANSI_YELLOW << _target << " has not been robotomized... yet!" << ANSI_RESET << std::endl;
			usleep(1000000);
		}
		return (true);
	}
	else
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because form has not been signed yet" << std::endl;
		return (false);
	}
}
