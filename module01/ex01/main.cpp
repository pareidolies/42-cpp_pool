# include "Zombie.hpp"

# define NB 7

int main()
{
    Zombie  *zombies = zombieHorde(NB, "Eurus");
    for (int i = 0; i < NB; i++)
    {
        std::cout << i + 1 << ": ";
        zombies[i].announce();
    }
    if (NB > 0)
        delete [] zombies;
    return (0);
}
