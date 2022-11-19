# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << ANSI_PURPLE << "constructor called for " << name << ANSI_RESET << std::endl;
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << ANSI_PURPLE << "destructor called for " << this->name << ANSI_RESET << std::endl;
}

void	Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
