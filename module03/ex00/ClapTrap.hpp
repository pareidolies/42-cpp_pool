#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RESET			"\x1b[0m"

class ClapTrap
{
	public:

		ClapTrap(void); //default constructor
		ClapTrap(ClapTrap const & copy); // constructeur de recopie
		ClapTrap	&operator=(ClapTrap const & rhs); // surcharge de l'opérateur d'affectation
		~ClapTrap(void); //destructeur
		ClapTrap(std::string const name); //name constructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:

		const std::string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;

};

#endif