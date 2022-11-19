#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_RESET			"\x1b[0m"

class Zombie
{
	public:
	    Zombie(std::string name);
	    ~Zombie(void);
	    void	announce(void) const;

	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif