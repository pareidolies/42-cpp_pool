# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) : _name("RobotomyRequestForm"), _isSigned(false), _gradeToSign(72), _gradeToExecute(45)
{
	std::cout << ANSI_BLUE << "Default RobotomyRequestForm constructor called" << ANSI_RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const name) : _name(name), _isSigned(false), _gradeToSign(72), _gradeToExecute(45)
{
	std::cout << ANSI_BLUE << "Name and grade RobotomyRequestForm constructor called" << ANSI_RESET << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (RobotomyRequestForm::GradeTooHighException());
	else if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (RobotomyRequestForm::GradeTooLowException());
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << ANSI_YELLOW << "RobotomyRequestForm copy constructor called" << ANSI_RESET << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << ANSI_YELLOW << "RobotomyRequestForm assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << ANSI_BLUE << "RobotomyRequestForm destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                 GETTERS                                     *
******************************************************************************/

std::string const RobotomyRequestForm::getName(void) const
{
	return (this->_name);
}

int	RobotomyRequestForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	RobotomyRequestForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/******************************************************************************
*                                 EXCEPTIONS                                  *
******************************************************************************/

const char *	RobotomyRequestForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: RobotomyRequestForm's grade is too high");
}

const char *	RobotomyRequestForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: RobotomyRequestForm's grade is too low");
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool			RobotomyRequestForm::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because RobotomyRequestForm has already been signed" << std::endl;
		return (false);
	}
	else if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		return (true);
	}
	else
	{
		throw (RobotomyRequestForm::GradeTooLowException());
		return (false);
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, RobotomyRequestForm const & rhs)
{
	stream << ANSI_PURPLE << rhs.getName() << ", RobotomyRequestForm required grade to sign " 
		<< rhs.getGradeToSign() << ", RobotomyRequestForm required grade to execute "
		<< rhs.getGradeToExecute() << "." << ANSI_RESET;
	return (stream);
}
