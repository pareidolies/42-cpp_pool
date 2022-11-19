#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <stdlib.h>
# include <string>

class Zombie
{
	public:
	    Zombie(void);
	    ~Zombie(void);
	    void	announce( void );

	private:
		std::string	name;
};

#endif