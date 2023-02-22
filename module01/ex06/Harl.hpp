/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:31:47 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:31:49 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define ANSI_RED		    "\x1b[91m"
# define ANSI_RESET			"\x1b[0m"

class Harl
{
	public:
        Harl(void);
        ~Harl(void);
		void	complain(std::string level) const;

	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
};

#endif
