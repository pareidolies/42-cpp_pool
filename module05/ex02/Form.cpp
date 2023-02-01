# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Form::Form(void) : _name("Form"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75)
{
	std::cout << ANSI_BLUE << "Default form constructor called" << ANSI_RESET << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
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

Form::Form(Form const & copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << ANSI_YELLOW << "Form copy constructor called" << ANSI_RESET << std::endl;
}

Form	&Form::operator=(Form const & rhs)
{
	std::cout << ANSI_YELLOW << "Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
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

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
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

bool			Form::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because form has already been signed" << std::endl;
		return (false);
	}
	else if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		return (true);
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
		<< rhs.getGradeToSign() << ", Form required grade to execute "
		<< rhs.getGradeToExecute() << "." << ANSI_RESET;
	return (stream);
}
