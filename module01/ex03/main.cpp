/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:31 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:30:32 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"
# include <iostream>

int main() 
{
    {
        std::cout << "---- HUMAN A TESTS ----" << std::endl;
        Weapon  club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    std::cout << std::endl;
    {
        std::cout << "---- HUMAN B TESTS ----" << std::endl;
        Weapon  club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    std::cout << std::endl;
    {
        std::cout << "---- EMPTY STRING TESTS ----" << std::endl;
        Weapon  club = Weapon("");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("sword");
        bob.attack(); 
    }
    std::cout << std::endl;
    {
        std::cout << "---- NULL TESTS ----" << std::endl;
        Weapon  club = Weapon();
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("");
        jim.attack();
        club.setType("net");
        jim.attack();
    }
    std::cout << std::endl;
    return 0; 
}
