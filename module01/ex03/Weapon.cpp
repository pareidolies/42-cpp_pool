# include "Weapon.hpp"

Weapon::Weapon(void)
{
    std::cout << ANSI_PURPLE << "constructor called" << ANSI_RESET << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << ANSI_PURPLE << "destructor called" << ANSI_RESET << std::endl;
}

std::string	&Weapon::getType(void)
{
    return (this->_type);
}

void	Weapon::setType(std::string newType)
{
    this->_type = newType;
}
