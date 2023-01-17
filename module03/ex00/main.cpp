# include "ClapTrap.hpp"

int main()
{
	ClapTrap	woolf = ClapTrap("Woolf");
	ClapTrap	labradoodle = ClapTrap();

	for (int i = 0; i < 10; i++)
	{
		woolf.attack("Labradoodle");
		labradoodle.takeDamage(1);
	}
	labradoodle.attack("Woolf");
	labradoodle.beRepaired(1);
    woolf.attack("Labradoodle");
	return (0);
}
