/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:28:42 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:28:44 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << ANSI_PURPLE << "constructor called for " << this->name << ANSI_RESET << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << ANSI_PURPLE << "destructor called for " << this->name << ANSI_RESET << std::endl;
}

void	Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
