# include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << ANSI_PURPLE << "constructor called" << ANSI_RESET << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << ANSI_PURPLE << "destructor called" << ANSI_RESET << std::endl;
}

void	Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
    this->name = name;
}
