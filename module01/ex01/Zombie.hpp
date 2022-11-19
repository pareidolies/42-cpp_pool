#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_RESET			"\x1b[0m"

class Zombie
{
	public:
	    Zombie(void);
	    ~Zombie(void);
	    void	announce(void);
		void	setName(std::string name);

	private:
		std::string	name;
};

Zombie*    zombieHorde(int N, std::string name);

#endif