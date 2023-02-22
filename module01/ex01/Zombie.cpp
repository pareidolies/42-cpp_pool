/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:29:18 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:29:19 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << ANSI_PURPLE << "constructor called" << ANSI_RESET << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << ANSI_PURPLE << "destructor called" << ANSI_RESET << std::endl;
}

void	Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
    this->name = name;
}
