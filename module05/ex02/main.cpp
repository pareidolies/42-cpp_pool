# include "Bureaucrat.hpp"
# include "ShrubberyCreationAForm.hpp"
# include "RobotomyRequestAForm.hpp"
# include "PresidentialPardonAForm.hpp"
# include "AForm.hpp"

# include <iostream>
# include <string>

int main()
{
	Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 70);
	Bureaucrat boss = Bureaucrat("Boss", 1);

	std::cout << bureaucrat << std::endl;
	std::cout << boss << std::endl;

	AForm *shrubbery = new ShrubberyCreationAForm("Garden");
	AForm *robotomy = new RobotomyRequestAForm("President");
	AForm *pardon = new PresidentialPardonAForm("Prisoner");

	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *pardon << std::endl;

	bureaucrat.signAForm(*shrubbery);
	bureaucrat.executeAForm(*shrubbery);

	bureaucrat.signAForm(*robotomy);
	bureaucrat.executeAForm(*robotomy);
	boss.executeAForm(*robotomy);

	bureaucrat.signAForm(*pardon);
	boss.signAForm(*pardon);
	boss.executeAForm(*pardon);

	delete shrubbery;
	delete robotomy;
	delete pardon;

	return (0);
}
