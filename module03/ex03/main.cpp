# include "DiamondTrap.hpp"

//vérifier les valeurs héritées

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

    ScavTrap	fox = ScavTrap("Fox");
	ScavTrap	mouse = ScavTrap("Mouse");

    fox.attack("Mouse");
    mouse.takeDamage(20);
    mouse.beRepaired(20);
    mouse.attack("Fox");
    fox.takeDamage(20);
	mouse.guardGate();

	FragTrap	lion = FragTrap("Lion");
	FragTrap	dolphin = FragTrap("Dolphin");

	lion.attack("Dolphin");
    dolphin.takeDamage(30);
    dolphin.beRepaired(30);
    dolphin.attack("Lion");
    lion.takeDamage(30);
	dolphin.highFivesGuys();

	DiamondTrap	cat = DiamondTrap("Cat");
	DiamondTrap	dog = DiamondTrap("Dog");

	dog.whoAmI();
	cat.whoAmI();

	cat.attack("Dog");
    dog.takeDamage(30);
    dog.beRepaired(30);
    dog.attack("Cat");
    cat.takeDamage(30);
	

	return (0);
}
