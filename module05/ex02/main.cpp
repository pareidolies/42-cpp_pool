# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Form.hpp"

# include <iostream>
# include <string>

int main()
{
	Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 70);
	Bureaucrat boss = Bureaucrat("Boss", 1);

	Form *shrubbery = new ShrubberyCreationForm("Garden");
	Form *robotomy = new RobotomyRequestForm("President");
	Form *pardon = new PresidentialPardonForm("Prisoner");

	bureaucrat.signForm(*shrubbery);
	bureaucrat.executeForm(*shrubbery);

	bureaucrat.signForm(*robotomy);
	bureaucrat.executeForm(*robotomy);
	boss.executeForm(*robotomy);

	bureaucrat.signForm(*pardon);
	boss.signForm(*pardon);
	boss.executeForm(*pardon);

	delete shrubbery;
	delete robotomy;
	delete pardon;

	return (0);
}
