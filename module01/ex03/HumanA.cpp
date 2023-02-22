/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:05 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:30:07 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon const & weapon) : _name(name), _weapon(weapon)
{
    if (this->_weapon.getType() == "")
    {
        std::cout << ANSI_YELLOW << "[...] new human A created (name : " << this->_name
        << ", hands)"
        << ANSI_RESET << std::endl;
    }
    else
    {
        std::cout << ANSI_YELLOW << "[...] new human A created (name : " << this->_name
        << ", type of weapon : " << this->_weapon.getType() << ")"
        << ANSI_RESET << std::endl;
    }
}

HumanA::~HumanA(void)
{
    std::cout << ANSI_YELLOW << "[...] destruction of human A (name : " << this->_name
    << ")"
    << ANSI_RESET << std::endl;
}

void	HumanA::attack(void)
{
    if (this->_weapon.getType() == "")
		std::cout << this->_name << " attacks with their hands!" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
