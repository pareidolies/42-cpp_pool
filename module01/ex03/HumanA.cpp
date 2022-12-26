# include "HumanA.hpp"

HumanA::HumanA(Weapon weapon)
{
    std::cout << ANSI_PURPLE << "constructor called" << ANSI_RESET << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << ANSI_PURPLE << "destructor called" << ANSI_RESET << std::endl;
}

void	HumanA::attack(void)
{
    std::cout << this->_name << "attacks with their" << this->_weapon.getType() std::endl;
}
