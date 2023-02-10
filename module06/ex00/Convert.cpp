# include "Convert.hpp"
# include "Form.hpp"
# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Convert::Convert(void) : _name("Convert"), _grade(75)
{
	std::cout << ANSI_BLUE << "Default Convert constructor called" << ANSI_RESET << std::endl;
}

Convert::Convert(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << ANSI_BLUE << "Name and grade Convert constructor called" << ANSI_RESET << std::endl;
	if (grade < 1)
		throw (Convert::GradeTooHighException());
	else if (grade > 150)
		throw (Convert::GradeTooLowException());
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Convert::Convert(Convert const & copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << ANSI_YELLOW << "Convert copy constructor called" << ANSI_RESET << std::endl;
}

Convert	&Convert::operator=(Convert const & rhs)
{
	std::cout << ANSI_YELLOW << "Convert assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Convert::~Convert(void)
{
	std::cout << ANSI_BLUE << "Convert destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                 GETTERS                                     *
******************************************************************************/

std::string const Convert::getName(void) const
{
	return (this->_name);
}

int	Convert::getGrade(void) const
{
	return (this->_grade);
}

/******************************************************************************
*                                 EXCEPTIONS                                  *
******************************************************************************/

const char *	Convert::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Convert's grade is too high");
}

const char *	Convert::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Convert's grade is too low");
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	Convert::upgrade(void)
{
	if (this->_grade - 1 < Convert::highestGrade)
		return (throw (Convert::GradeTooHighException()));
	else
	{
		this->_grade--;
		std::cout << "Convert " << this->_name << " got upgraded." << std::endl;
	}
}

void	Convert::downgrade(void)
{
	if (this->_grade + 1 > Convert::lowestGrade)
		return (throw (Convert::GradeTooLowException()));
	else
	{
		this->_grade++;
		std::cout << "Convert " << this->_name << " got downgraded." << std::endl;
	}
}

void	Convert::signForm(Form & form)
{
	try
	{
		if (form.beSigned(*this))
			std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because Convert's grade is too low" << std::endl;;
	}
}

void		Convert::executeForm(Form const & form)
{
	try
	{
		if (form.execute(*this))
			std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because Convert's grade is too low" << std::endl;;
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, Convert const & rhs)
{
	stream << ANSI_PURPLE << rhs.getName() << ", Convert grade " 
		<< rhs.getGrade() << "." << ANSI_RESET;
	return (stream);
}
