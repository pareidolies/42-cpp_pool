# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : _name("ShrubberyCreationForm"), _isSigned(false), _gradeToSign(145), _gradeToExecute(137)
{
	std::cout << ANSI_BLUE << "Default ShrubberyCreationForm constructor called" << ANSI_RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name) : _name(name), _isSigned(false), _gradeToSign(145), _gradeToExecute(137)
{
	std::cout << ANSI_BLUE << "Name and grade ShrubberyCreationForm constructor called" << ANSI_RESET << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (ShrubberyCreationForm::GradeTooHighException());
	else if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (ShrubberyCreationForm::GradeTooLowException());
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << ANSI_YELLOW << "ShrubberyCreationForm copy constructor called" << ANSI_RESET << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << ANSI_YELLOW << "ShrubberyCreationForm assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << ANSI_BLUE << "ShrubberyCreationForm destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                 GETTERS                                     *
******************************************************************************/

std::string const ShrubberyCreationForm::getName(void) const
{
	return (this->_name);
}

int	ShrubberyCreationForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	ShrubberyCreationForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/******************************************************************************
*                                 EXCEPTIONS                                  *
******************************************************************************/

const char *	ShrubberyCreationForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: ShrubberyCreationForm's grade is too high");
}

const char *	ShrubberyCreationForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: ShrubberyCreationForm's grade is too low");
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool			ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because ShrubberyCreationForm has already been signed" << std::endl;
		return (false);
	}
	else if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		return (true);
	}
	else
	{
		throw (ShrubberyCreationForm::GradeTooLowException());
		return (false);
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, ShrubberyCreationForm const & rhs)
{
	stream << ANSI_PURPLE << rhs.getName() << ", ShrubberyCreationForm required grade to sign " 
		<< rhs.getGradeToSign() << ", ShrubberyCreationForm required grade to execute "
		<< rhs.getGradeToExecute() << "." << ANSI_RESET;
	return (stream);
}
