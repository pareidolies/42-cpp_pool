# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Form::Form(void) : _name("Form"), _gradeToSign(75), _gradeToExecute(75), _isSigned(false)
{
	std::cout << ANSI_BLUE << "Default form constructor called" << ANSI_RESET << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	std::cout << ANSI_BLUE << "Name and grade form constructor called" << ANSI_RESET << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (Form::GradeTooHighException());
	else if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Form::Form(Form const & copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToSign(copy._gradeToExecute), _isSigned(copy._isSigned)
{
	std::cout << ANSI_YELLOW << "Form copy constructor called" << ANSI_RESET << std::endl;
}

Form	&Form::operator=(Form const & rhs)
{
	std::cout << ANSI_YELLOW << "Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
	{
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExecute = rhs._gradeToExecute;
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Form::~Form(void)
{
	std::cout << ANSI_BLUE << "Form destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                 GETTERS                                     *
******************************************************************************/

std::string const Form::getName(void) const
{
	return (this->_name);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/******************************************************************************
*                                 EXCEPTIONS                                  *
******************************************************************************/

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Form's grade is too high");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Form's grade is too low");
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool				Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		return(this->_isSigned = true);
	else if ()
	{

		
	}
	else
	{
		throw (Form::GradeTooLowException());
		return (false);
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, Form const & rhs)
{
	stream << ANSI_PURPLE << rhs.getName() << ", Form required grade to sign " 
		<< rhs.getGradeToSign() << ", Form required grade to sign "
		<< rhs.getGradeToExecute() << "." << ANSI_RESET;
	return (stream);
}
