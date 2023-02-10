# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>
# include <unistd.h>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation Form", 145, 137)
{
	this->_target = "Garden";
	std::cout << ANSI_BLUE << "Default Shrubbery Creation Form constructor called" << ANSI_RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137)
{
	this->_target = target;
	std::cout << ANSI_BLUE << "Target Shrubbery Creation Form constructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : Form(copy)
{
	*this = copy;
	std::cout << ANSI_YELLOW << "Shrubbery Creation Form copy constructor called" << ANSI_RESET << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << ANSI_YELLOW << "Shrubbery Creation Form assignment operator called" << ANSI_RESET << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	Form::operator=(rhs);
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << ANSI_BLUE << "Shrubbery Creation Form destructor called" << ANSI_RESET << std::endl;
}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw (GradeTooLowException());
		return (false);
	}
	else if (this->getStatus() == true)
	{
		std::string		file;
		file = _target + "_shrubbery";
		std::cout << "Shrubbery creation in progress..." << ANSI_RESET << std::endl;
		std::ofstream	ofs(file.c_str());
		if (!ofs.good())
		{
			std::cerr << "Opening of file (" << file << ") failed" << std::endl;
			return (false);
		}
		ofs << K1 << std::endl
			<< K2 << std::endl
			<< K3 << std::endl
			<< K4 << std::endl
			<< K5 << std::endl
			<< K6 << std::endl
			<< K7 << std::endl
			<< K8 << std::endl
			<< K9 << std::endl
			<< K10 << std::endl
			<< K11 << std::endl << std::endl
			<< L1 << std::endl
			<< L2 << std::endl
			<< L3 << std::endl
			<< L4 << std::endl
			<< L5 << std::endl
			<< L6 << std::endl
			<< L7 << std::endl
			<< L8 << std::endl
			<< L9 << std::endl
			<< L10 << std::endl << std::endl
			<< M1 << std::endl
			<< M2 << std::endl
			<< M3 << std::endl
			<< M4 << std::endl
			<< M5 << std::endl
			<< M6 << std::endl
			<< M7 << std::endl
			<< M8 << std::endl
			<< M9 << std::endl
			<< M10 << std::endl
			<< M11 << std::endl
			<< M12 << std::endl
			<< M13 << std::endl << std::endl;
		usleep(1000000);
		std::cout << "Done!" << ANSI_RESET << std::endl;
		usleep(1000000);
		return (true);
	}
	else
	{
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because form has not been signed yet" << std::endl;
		return (false);
	}
}
