# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Form.hpp"
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
	
	Form *shrubbery = intern.makeForm("shrubbery creation", "Garden");
	Form *robotomy = intern.makeForm("robotomy request", "President");
	Form *pardon = intern.makeForm("presidential pardon", "Prisoner");
	Form *error = intern.makeForm("error", "error");

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
	delete error;

	return (0);
}
