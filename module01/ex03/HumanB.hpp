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