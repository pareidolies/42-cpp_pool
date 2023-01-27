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

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "TEST 2 : Shallow and deep copy" << std::endl << std::endl;

	Dog		*dog = new Dog();
	Dog		*deepdog;
	Dog		*shallowdog;

	dog->setIdea(0, "Dogs are better than cats");

	std::cout << "Dog idea : " << dog->getIdea(0) << std::endl;
	std::cout << "Dog idea address : " << &dog->getIdea(0) << std::endl;

	deepdog = new Dog(*dog);

	std::cout << "Deep dog idea : " << deepdog->getIdea(0) << std::endl;
	std::cout << "Deep dog idea address : " << deepdog->getIdea(0) << std::endl;

	shallowdog = dog;

	std::cout << "Shallow dog idea : " << shallowdog->getIdea(0) << std::endl;
	std::cout << "Shallow dog idea address : " << shallowdog->getIdea(0) << std::endl;

	delete dog;
	//delete deepdog;

	return (0);
}
