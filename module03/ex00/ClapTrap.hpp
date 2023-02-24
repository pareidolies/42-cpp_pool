#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class ClapTrap
{
	public:

		ClapTrap(void); //default constructor
		ClapTrap(std::string const name); //name constructor
		ClapTrap(ClapTrap const & copy); //copy constructor
		ClapTrap	&operator=(ClapTrap const & rhs); //copy assignment operator
		~ClapTrap(void); //destructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:

		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;

};

#endif