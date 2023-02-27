# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

# include "WrongAnimal.hpp"
# include "WrongDog.hpp"
# include "WrongCat.hpp"

# include <iostream>
# include <string>

int main()
{
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
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 : Shallow and deep copy" << std::endl << std::endl;

		Dog		*dog = new Dog();
		Dog		*deepdog;
		Dog		*shallowdog;

		dog->getBrain()->setIdea(0, "Dogs are better than cats");

		std::cout << "Dog idea : " << dog->getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl;

		deepdog = new Dog(*dog);
		std::cout << "Deep dog idea after copy : " << deepdog->getBrain()->getIdea(0) << std::endl;
		deepdog->getBrain()->setIdea(0, "No, Cats are better than dogs!");
		std::cout << "Deep dog idea after setting new idea : " << deepdog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Did dog initial idea change ? " << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog idea address : " << dog->getBrain()->getIdeaAddress(0) << std::endl;
		std::cout << "Deep dog idea address : " << deepdog->getBrain()->getIdeaAddress(0) << std::endl;

		std::cout << std::endl;

		shallowdog = dog;
		std::cout << "Shallow dog idea after copy : " << shallowdog->getBrain()->getIdea(0) << std::endl;
		shallowdog->getBrain()->setIdea(0, "No, Cats are better than dogs!");
		std::cout << "Shallow dog idea after setting new idea : " << shallowdog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Did dog initial idea change ? " << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog idea address : " << dog->getBrain()->getIdeaAddress(0) << std::endl;
		std::cout << "Deep dog idea address : " << shallowdog->getBrain()->getIdeaAddress(0) << std::endl;

		delete dog;
		delete deepdog;
	}
	return (0);
}
