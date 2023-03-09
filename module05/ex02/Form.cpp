# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

AForm::AForm(void) : _name("AForm"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75)
{
	//std::cout << ANSI_BLUE << "Default Form constructor called" << ANSI_RESET << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << ANSI_BLUE << "Name and grade Form constructor called" << ANSI_RESET << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (AForm::GradeTooHighException());
	else if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

AForm::AForm(AForm const & copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	//std::cout << ANSI_YELLOW << "Form copy constructor called" << ANSI_RESET << std::endl;
}

AForm	&AForm::operator=(AForm const & rhs)
{
	//std::cout << ANSI_YELLOW << "Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

AForm::~AForm(void)
{
	std::cout << ANSI_BLUE << "Form destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                 GETTERS                                     *
******************************************************************************/

std::string const AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool	AForm::getStatus(void) const
{
	return (this->_isSigned);
}

/******************************************************************************
*                                 EXCEPTIONS                                  *
******************************************************************************/

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Form's grade is too high");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Form's grade is too low");
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool			AForm::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because Form has already been signed" << std::endl;
		return (false);
	}
	else if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		return (true);
	}
	else
	{
		throw (AForm::GradeTooLowException());
		return (false);
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, AForm const & rhs)
{
	stream << ANSI_PURPLE << rhs.getName() << ", Form required grade to sign " 
		<< rhs.getGradeToSign() << ", Form required grade to execute "
		<< rhs.getGradeToExecute() << "." << ANSI_RESET;
	return (stream);
}
