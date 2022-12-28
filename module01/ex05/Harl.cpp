#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level) const
{
	void (Harl::*f[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string alert[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == alert[i])
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << ANSI_RED << "Level <" << level << "> unknown." << ANSI_RESET << std::endl;
}

void	Harl::debug(void) const
{
	std::cout << "[DEBUG]" << std::endl
              << "I love having extra bacon for my " 
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do !"
			  << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[INFO]" << std::endl
              << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger ! "
			  << "If you did, I wouldn’t be asking for more !"
			  << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[WARNING]" << std::endl
              << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working "
			  << "here since last month."
			  << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ERROR]" << std::endl
              << "This is unacceptable ! I want to speak to the manager now."
			  << std::endl;
}
