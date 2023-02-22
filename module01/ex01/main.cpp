/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:29:06 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:29:07 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

# define NB 7

int main()
{
    Zombie  *zombies = zombieHorde(NB, "Eurus");
    for (int i = 0; i < NB; i++)
    {
        std::cout << i + 1 << ": ";
        zombies[i].announce();
    }
    if (NB > 0)
        delete [] zombies;
    return (0);
}
