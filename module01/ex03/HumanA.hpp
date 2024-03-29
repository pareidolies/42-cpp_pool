/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:11 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:30:12 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA
{
	public:
	    HumanA(std::string const name, Weapon const & weapon);
	    ~HumanA(void);
	    void	attack(void);

	private:
		std::string	const _name;
		Weapon		const & _weapon;
};

#endif
