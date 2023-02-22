# include "Zombie.hpp"

int main()
{
    Zombie  *zombie = newZombie("Sherlock");
    zombie->announce();
    delete  zombie;
    randomChump("Watson");
    return (0);
}
