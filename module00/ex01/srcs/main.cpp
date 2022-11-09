# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <stdlib.h>
# include <iostream>
# include <string>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_COLOR_RESET		"\x1b[0m"

void	say_hello()
{
	std::cout << ANSI_PURPLE << "---------------------------------------" << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_PURPLE << "  Welcome to your (awesome) phonebook " << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_PURPLE << "---------------------------------------" << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_PURPLE << "Would you like to ADD, SEARCH or EXIT ?" << ANSI_COLOR_RESET << std::endl;
}

int main()
{
	PhoneBook	book;
	std::string	choice;
	int	i;
	int	index;

	i = 0;
	say_hello();
	while (1)
	{
		std::cout << "> ";
		if (std::getline(std::cin,choice) == NULL)
			return (1);
		else if (choice == "ADD")
		{
			book.add_contact(i);
			i++;
			if (i == 8)
				i = 0;
		}
		else if (choice == "SEARCH")
		{
			book.print_phonebook();
			std::cout << ANSI_PURPLE << "For which contact would you like to see the information? " << ANSI_COLOR_RESET << std::endl;
			std::cout << "> ";
			if (std::getline(std::cin, choice) == NULL)
				return (1);
			if (choice.length() == 1)
			{
				index = std::atoi(choice.c_str()) - 1;
				if (index < book.number_of_contacts() && index >= 0)
					book.print_contact(index);
			}
		}
		else if (choice == "EXIT")
		{
			exit(0);
		}
	}
	return (0);
}
