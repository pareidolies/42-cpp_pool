# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

# include <iostream>
# include <string>

int main()
{
	Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 70);
	Bureaucrat boss = Bureaucrat("Boss", 1);

	std::cout << bureaucrat << std::endl;
	std::cout << boss << std::endl;

	std::cout << std::endl;

	AForm *shrubbery = new ShrubberyCreationForm("Garden");
	AForm *robotomy = new RobotomyRequestForm("President");
	AForm *pardon = new PresidentialPardonForm("Prisoner");

	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *pardon << std::endl;

	std::cout << std::endl;

	bureaucrat.signForm(*shrubbery);
	bureaucrat.executeForm(*shrubbery);

	std::cout << std::endl;

	bureaucrat.signForm(*robotomy);
	bureaucrat.executeForm(*robotomy);
	boss.executeForm(*robotomy);

	std::cout << std::endl;

	bureaucrat.signForm(*pardon);
	boss.executeForm(*pardon);
	boss.signForm(*pardon);
	boss.executeForm(*pardon);

	std::cout << std::endl;

	delete shrubbery;
	delete robotomy;
	delete pardon;

	return (0);
}
