# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

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
	return (0);
}
