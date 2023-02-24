# include "ScavTrap.hpp"

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
	std::cout << std::endl;
	{
    	ScavTrap	fox = ScavTrap("Fox");
		ScavTrap	mouse = ScavTrap("Mouse");

    	fox.attack("Mouse");
    	mouse.takeDamage(20);
    	mouse.beRepaired(20);
    	mouse.attack("fox");
    	fox.takeDamage(20);
		mouse.guardGate();
		for (int i = 0; i < 5; i++)
		{
			mouse.attack("fox");
    		fox.takeDamage(20);
		}
		fox.attack("Mouse");
		fox.guardGate();
	}
	return (0);
}
