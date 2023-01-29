# include "Bureaucrat.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(75)
{
	std::cout << ANSI_BLUE << "Default bureaucrat constructor called" << ANSI_RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << ANSI_BLUE << "Name and grade bureaucrat constructor called" << ANSI_RESET << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << ANSI_YELLOW << "Bureaucrat copy constructor called" << ANSI_RESET << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << ANSI_YELLOW << "Bureaucrat assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Bureaucrat::~Bureaucrat(void)
{
	std::cout << ANSI_BLUE << "Bureaucrat destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                 GETTERS                                     *
******************************************************************************/

std::string const Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/******************************************************************************
*                                 EXCEPTIONS                                  *
******************************************************************************/

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Bureaucrat's grade is too high");
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Bureaucrat's grade is too low");
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Bureaucrat::upgrade(void)
{
	if (this->_grade - 1 < Bureaucrat::highestGrade)
		return (throw (Bureaucrat::GradeTooHighException()));
	else
	{
		this->_grade--;
		std::cout << "Bureaucrat " << this->_name << " got upgraded." << std::endl;
	}
}

void	Bureaucrat::downgrade(void)
{
	if (this->_grade + 1 > Bureaucrat::highestGrade)
		return (throw (Bureaucrat::GradeTooLowException()));
	else
	{
		this->_grade++;
		std::cout << "Bureaucrat " << this->_name << " got downgraded." << std::endl;
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, Bureaucrat const & rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " 
		<< rhs.getGrade() << "." << std::endl;
	return (stream);
}
