# include "Intern.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Intern::Intern(void)
{
	std::cout << ANSI_BLUE << "Default intern constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Intern::Intern(Intern const & copy)
{
	*this = copy;
	std::cout << ANSI_YELLOW << "Intern copy constructor called" << ANSI_RESET << std::endl;
}

Intern	&Intern::operator=(Intern const & rhs)
{
	std::cout << ANSI_YELLOW << "Intern assignment operator called" << ANSI_RESET << std::endl;
	(void) rhs;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Intern::~Intern(void)
{
	std::cout << ANSI_BLUE << "Intern destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

Form *Intern::makeShrubberyCreationForm(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string form, std::string target)
{
	std::string name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *(Intern::*fnct[3])(std::string target) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (name[i].compare(form) == 0)
		{
			std::cout << "Intern creates " << name[i] << " form" << std::endl;
			return (this->*(fnct[i]))(target);
		}
	}
	std::cerr << "Error: The form " << form << " doesn't exist" << std::endl;
	return (NULL);
}
