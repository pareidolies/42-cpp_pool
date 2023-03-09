# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"
# include "Intern.hpp"

# include <iostream>
# include <string>

int main()
{
	Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 70);
	Bureaucrat boss = Bureaucrat("Boss", 1);
	Intern intern = Intern();

	std::cout << bureaucrat << std::endl;
	std::cout << boss << std::endl;

	std::cout << std::endl;
	
	AForm *shrubbery = intern.makeForm("shrubbery creation", "Garden");
	AForm *robotomy = intern.makeForm("robotomy request", "President");
	AForm *pardon = intern.makeForm("presidential pardon", "Prisoner");
	AForm *error = intern.makeForm("error", "error");

	std::cout << std::endl;

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
	boss.signForm(*pardon);
	boss.executeForm(*pardon);

	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete error;

	return (0);
}
