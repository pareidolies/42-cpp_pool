#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

typedef struct e_Data
{
	std::string		value;
	char			c;
	float			f;
	double			d;
}				Data;

class Serializer
{
	public:

		Serializer(void); //default constructor
		Serializer(Serializer const & copy); //copy constructor
		~Serializer(void); //destructor

		Serializer	&operator=(Serializer const & rhs); //assignement operator

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);

	private:
	
};

#endif