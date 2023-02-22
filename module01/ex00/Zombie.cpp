# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << ANSI_PURPLE << "constructor called for " << this->name << ANSI_RESET << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << ANSI_PURPLE << "destructor called for " << this->name << ANSI_RESET << std::endl;
}

void	Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
