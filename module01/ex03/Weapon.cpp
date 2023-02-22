/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:40 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:30:41 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string const type) : _type(type)
{
    if (type == "")
        std::cout << ANSI_PURPLE << "[...] new weapon created (type : empty)" << ANSI_RESET << std::endl;
    else
        std::cout << ANSI_PURPLE << "[...] new weapon created (type : " << this->_type << ")" << ANSI_RESET << std::endl;
}

Weapon::Weapon(void) : _type("")
{
    std::cout << ANSI_PURPLE << "[...] new weapon created (type : empty)" << ANSI_RESET << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << ANSI_PURPLE << "[...] destruction of weapon (type : " << this->_type << ")" << ANSI_RESET << std::endl;
}

std::string const &Weapon::getType(void) const
{
    return (this->_type);
}

void	Weapon::setType(std::string const type)
{
    this->_type = type;
}
