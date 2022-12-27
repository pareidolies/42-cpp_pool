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