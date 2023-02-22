/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:28:20 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:28:22 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    Zombie  *zombie = newZombie("Sherlock");
    zombie->announce();
    delete  zombie;
    randomChump("Watson");
    return (0);
}
