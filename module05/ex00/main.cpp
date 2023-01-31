# include "Bureaucrat.hpp"

# include <iostream>
# include <string>

int main()
{
	{
		try
		{
			Bureaucrat MrPaddington = Bureaucrat("Mr Paddington", 151);
			std::cout << MrPaddington << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat MrsPaddington = Bureaucrat("MrsPaddington", 0);
			std::cout << MrsPaddington << std::endl;
			
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat MrSmith = Bureaucrat("Mr Smith", 75);
			std::cout << MrSmith << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat MrsSmith = Bureaucrat("Mrs Smith", 150);
			MrsSmith.downgrade();
			std::cout << MrsSmith << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat MrJones = Bureaucrat("Mr Jones", 1);
			MrJones.upgrade();
			std::cout << MrJones << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat MrsJones = Bureaucrat("MrsJones", 75);
			std::cout << MrsJones << std::endl;
			MrsJones.upgrade();
			std::cout << MrsJones << std::endl;
			MrsJones.downgrade();
			std::cout << MrsJones << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
