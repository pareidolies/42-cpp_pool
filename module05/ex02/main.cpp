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

	std::cout << bureaucrat << std::endl;
	std::cout << boss << std::endl;

	Form *shrubbery = new ShrubberyCreationForm("Garden");
	Form *robotomy = new RobotomyRequestForm("President");
	Form *pardon = new PresidentialPardonForm("Prisoner");

	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *pardon << std::endl;

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
