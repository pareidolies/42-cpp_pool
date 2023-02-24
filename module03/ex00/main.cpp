# include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap	woolf = ClapTrap("Woolf");
		ClapTrap	labradoodle = ClapTrap("Labradoodle");

		for (int i = 0; i < 10; i++)
		{
			woolf.attack("Labradoodle");
			labradoodle.takeDamage(1);
		}
		labradoodle.attack("Woolf");
		labradoodle.beRepaired(1);
	    woolf.attack("Labradoodle");
	}

	{
		ClapTrap	fox = ClapTrap("Fox");
		ClapTrap	mouse = ClapTrap("Mouse");

	    fox.attack("Mouse");
	    mouse.takeDamage(9);
	    mouse.beRepaired(9);
	    mouse.attack("fox");
	    fox.takeDamage(1);
	}
	return (0);
}
