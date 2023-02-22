/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:30:46 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:30:48 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RESET			"\x1b[0m"

class Weapon
{
	public:
	    Weapon(std::string const type);
		Weapon(void);
	    ~Weapon(void);
	    std::string	const &getType(void) const;
		void	setType(std::string const type);

	private:
		std::string	_type;
};

#endif
