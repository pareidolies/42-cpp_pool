# include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{

}

std::string	Contact::give_first_name()
{
	return first_name;
}

std::string	Contact::give_last_name()
{
	return last_name;
}

std::string	Contact::give_nickname()
{
	return nickname;
}

std::string	Contact::give_phone_number()
{
	return phone_number;
}

std::string	Contact::give_darkest_secret()
{
	return darkest_secret;
}

void	Contact::change_contact(std::string str1, std::string str2, std::string str3,std::string str4,std::string str5)
{
	first_name = str1;
	last_name = str2;
	nickname = str3;
	phone_number = str4;
	darkest_secret = str5;
}
