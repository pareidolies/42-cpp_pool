#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_RESET			"\x1b[0m"

class Weapon
{
	public:
	    Weapon(void);
	    ~Weapon(void);
	    std::string	&getType(void);
		void	setType(std::string newtype);

	private:
		std::string	_type;
};

#endif