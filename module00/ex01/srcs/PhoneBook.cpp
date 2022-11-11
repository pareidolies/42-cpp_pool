# include "PhoneBook.hpp"

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_COLOR_RESET	"\x1b[0m"

PhoneBook::PhoneBook()
{
	nbr_contacts = 0;
}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::add_contact(int i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	darkest_secret;
	std::string	nickname;

	std::cout << ANSI_PURPLE << "First name: " << ANSI_COLOR_RESET;
	if (std::getline(std::cin, first_name) == NULL || first_name == "")
		exit (1);
	std::cout << "\nfirst:" << first_name;
	std::cout << ANSI_PURPLE << "Last name: " << ANSI_COLOR_RESET;
	if (std::getline(std::cin, last_name) == NULL || first_name == "")
		exit (1);
	std::cout << ANSI_PURPLE << "Nickname: " << ANSI_COLOR_RESET;
	if (std::getline(std::cin, nickname) == NULL || first_name == "")
			exit (1);
	std::cout << ANSI_PURPLE << "Phone number: " << ANSI_COLOR_RESET;
	if (std::getline(std::cin, phone_number) == NULL || first_name == "")
		exit (1);
	std::cout << ANSI_PURPLE << "Darkest secret: " << ANSI_COLOR_RESET;
	if (std::getline(std::cin, darkest_secret) == NULL || first_name == "")
			exit (1);
	if (nbr_contacts < 8)
		nbr_contacts++;
	List[i].change_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

int	PhoneBook::number_of_contacts(void)
{
	return (nbr_contacts);
}

void    PhoneBook::truncate_text(std::string str)
{
	int			i;

	i = 0;
	if (str.length() <= 10)
	{
		i = str.length();
		while(i < 10)
		{
			std::cout << " ";
			i++;
		}
		std::cout << str;
	}
	else
	{
		while(i < 9)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << ".";
	}
}

void	PhoneBook::print_phonebook(void)
{
	int 		i;
	std::string	str;

	i = 0;
	std::cout << ANSI_GREEN << "|" << std::setw(10) << "Index" << "|" 
	        << std::setw(10) << "First name" << "|" 
			<< std::setw(10) << "Last name" << "|" 
			<< std::setw(10) << "Nickname" << "|" << ANSI_COLOR_RESET << std::endl;
	while (i < nbr_contacts)
	{
		std::cout << ANSI_GREEN << "|         " << i + 1 << "|";
		truncate_text(List[i].give_first_name());
		std::cout << "|";
		truncate_text(List[i].give_last_name());
		std::cout << "|";
		truncate_text(List[i].give_nickname());
		std::cout << "|" << ANSI_COLOR_RESET << std::endl;
		i++;
	}
}

void	PhoneBook::print_contact(int i)
{
	std::cout << "First name: " << List[i].give_first_name() << std::endl;
	std::cout << "Last name: " << List[i].give_last_name() << std::endl;
	std::cout << "Nickname: " << List[i].give_nickname() << std::endl;
	std::cout << "Phone number: " << List[i].give_phone_number() << std::endl;
	std::cout << "Darkest secret: " << List[i].give_darkest_secret() << std::endl;
}
