# include "ScalarConverter.hpp"

int main()
{
	ScalarConverter scalar; 

	scalar.convert("0");
	std::cout << scalar << std::endl;
	scalar.convert("nan");
	std::cout << scalar << std::endl;
	scalar.convert("42.0f");
	std::cout << scalar << std::endl;
	scalar.convert("42.0");
	std::cout << scalar << std::endl;
	return (0);
}
