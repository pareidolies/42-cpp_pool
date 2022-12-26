#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
	public:
	    HumanB(void);
	    ~HumanB(void);
	    void	attack(void);

	private:
		std::string	_name;
		Weapon		_weapon;
};

#endif