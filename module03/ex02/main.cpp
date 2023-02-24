# include "ScavTrap.hpp"
# include "FragTrap.hpp"

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
	    mouse.attack("Fox");
	    fox.takeDamage(20);
		mouse.guardGate();
	}
	std::cout << std::endl;
	{
		FragTrap	lion = FragTrap("Lion");
		FragTrap	dolphin = FragTrap("Dolphin");

		lion.attack("Dolphin");
    	dolphin.takeDamage(30);
    	dolphin.beRepaired(30);
    	dolphin.attack("Lion");
    	lion.takeDamage(30);
		dolphin.highFivesGuys();
	}
	return (0);
}
