/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:24 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:30:25 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
	public:
		HumanB(std::string const name, Weapon * weapon);
	    HumanB(std::string const name);
	    ~HumanB(void);
	    void	attack(void);
		void    setWeapon(Weapon & weapon);

	private:
		std::string	const _name;
		Weapon		* _weapon;
};

#endif
