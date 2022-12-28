#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << ANSI_RED << "Usage : " << argv[0] << " <filter>" << ANSI_RESET << std::endl;
		return (1);
	}
	harl.complain(std::string(argv[1]));
	return (0);
}