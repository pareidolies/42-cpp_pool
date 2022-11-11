# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <stdlib.h>
# include <iostream>
# include <string>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_COLOR_RESET	"\x1b[0m"

int main()
{
	PhoneBook	book;
	std::string	choice;
	int	i;
	int	index;

	i = 0;
	while (1)
	{
		std::cout << "> ";
		if (std::getline(std::cin,choice) == NULL)
			return (1);
		else if (choice == "ADD")
		{
			if (i == MEMORY)
			{
				i = 0;
				std::cout << ANSI_PURPLE << "Not enough memory! Your oldest contact will be replaced by the new one." << ANSI_COLOR_RESET << std::endl;
			}
			book.add_contact(i);
			i++;
		}
		else if (choice == "SEARCH")
		{
			book.print_phonebook();
			std::cout << ANSI_PURPLE << "For which contact would you like to see the information?" << ANSI_COLOR_RESET << std::endl;
			std::cout << "> ";
			if (std::getline(std::cin, choice) == NULL)
				return (1);
			if (choice.length() == 1)
			{
				index = std::atoi(choice.c_str()) - 1;
				if (index < book.number_of_contacts() && index >= 0)
					book.print_contact(index);
				else
					std::cout << ANSI_PURPLE << "Error: The id written in arabic numerals of the requested contact was expected. " << ANSI_COLOR_RESET << std::endl;
			}
			else
				std::cout << ANSI_PURPLE << "Error: The id written in arabic numerals of the requested contact was expected. " << ANSI_COLOR_RESET << std::endl;
		}
		else if (choice == "EXIT")
			return(0);
	}
	return (0);
}
