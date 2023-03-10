# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter scalar; 

	if (argc == 2)
	{
		scalar.convert(argv[1]);
		std::cout << scalar;
	}
	else
		std::cout << "Usage : ./scalar <TO CONVERT>" << std::endl;
	return (0);
}
