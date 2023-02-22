/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:29:28 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:29:29 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return(NULL);
    Zombie  *zombies = new Zombie[N];
    for (int i = 0 ; i < N; i++)
        zombies[i].setName(name);
    return (zombies);
}
