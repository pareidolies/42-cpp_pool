# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

# include "WrongAnimal.hpp"
# include "WrongDog.hpp"
# include "WrongCat.hpp"

# include <iostream>

int main() 
{
	const Animal* animal = new Animal(); 
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << animal->getType() << " : ";
	animal->makeSound();
	std::cout << dog->getType() << " : ";
	dog->makeSound();
	std::cout << cat->getType() << " : ";
	cat->makeSound();
	delete animal;
	delete dog;
	delete cat;

	const WrongAnimal* wronganimal = new WrongAnimal(); 
	const WrongAnimal* wrongdog = new WrongDog();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << wronganimal->getType() << " : ";
	wronganimal->makeSound();
	std::cout << wrongdog->getType() << " : ";
	wrongdog->makeSound();
	std::cout << wrongcat->getType() << " : ";
	wrongcat->makeSound();
	delete wronganimal;
	delete wrongdog;
	delete wrongcat;

	return (0);
}
