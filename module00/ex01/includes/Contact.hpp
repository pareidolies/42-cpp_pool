#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Contact
{
	public:
	    Contact(void);
	    ~Contact(void);
    	std::string	give_first_name(void);
		std::string	give_last_name(void);
		std::string	give_nickname(void);
		std::string	give_phone_number(void);
		std::string	give_darkest_secret(void);
		void		change_contact(std::string str1, std::string str2, std::string str3,std::string str4,std::string str5);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif