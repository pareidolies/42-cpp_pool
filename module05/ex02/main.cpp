# include "Bureaucrat.hpp"
# include "Form.hpp"

# include <iostream>
# include <string>

int main()
{
	Bureaucrat MrPaddington = Bureaucrat("Mr Paddington", 100);
	Bureaucrat MrsPaddington = Bureaucrat("Mrs Paddington", 50);
	{
		try
		{
			Form F00 = Form("F00", 0, 75);
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form F01 = Form("F01", 75, 151);
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	Form F02 = Form("F02", 75, 75);
	std::cout << F02 << std::endl;
	MrPaddington.signForm(F02);
	MrsPaddington.signForm(F02);
	MrsPaddington.signForm(F02);
	return (0);
}
