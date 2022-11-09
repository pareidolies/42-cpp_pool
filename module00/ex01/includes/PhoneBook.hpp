#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <iomanip>

class PhoneBook
{

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void	add_contact(int i);
	void	print_phonebook();
	void	print_contact(int i);
	int		number_of_contacts();

	private:
		Contact	List[8];
		int		nbr_contacts;
        void    truncate_text(std::string str);
};

#endif