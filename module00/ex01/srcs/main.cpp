#include "Phonebook.class.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

void	say_hello()
{
	std::cout << "*** Welcome to your -awesome- phonebook ***" << std::endl;
	std::cout << "Do you want to 1/ADD 2/SEARCH 3/EXIT ?" << std::endl;
	std::cout << "> ";

}

int main(int argc, char **argv)
{
	std::string	choice;

	(void)argv;
	if (argc == 1)
	{
		say_hello();
		std::getline(std::cin,choice);
		std::cout << "Your choice is " << choice << std::endl;
		if (choice == "ADD")
		{

		}
		else if (choice == SEARCH)
		{

		}
		else if (choice == EXIT)
		{
			
		}
	}
	return (0);
}
