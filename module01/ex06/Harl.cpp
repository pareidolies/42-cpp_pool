/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:31:41 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:31:42 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int index;

	index = 5;
	for (int i = 0; i < 4; i++)
	{
		if (level == alert[i])
			index = i;
	}
	switch (index)
	{
		case 0:
			(this->*f[index])();
			index++;
		case 1:
			(this->*f[index])();
			index++;
		case 2:
			(this->*f[index])();
			index++;
		case 3:
			(this->*f[index])();
			index++;
			break;
		default :
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
	}
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
