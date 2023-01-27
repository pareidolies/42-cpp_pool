# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

# include "WrongAnimal.hpp"
# include "WrongDog.hpp"
# include "WrongCat.hpp"

# include <iostream>

int main()
{
	Animal	*animals[4];

	std::cout << "TEST 1 : Constructor and destructor order" << std::endl << std::endl;

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 2; i++)
		delete animals[i];
	for (int i = 2; i < 4; i++)
		delete animals[i];

	std::cout << "TEST 2 : Shallow and deep copy" << std::endl << std::endl;


	return (0);
}
