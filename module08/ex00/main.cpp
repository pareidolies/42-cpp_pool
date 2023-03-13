# include "easyfind.hpp"

# include <vector>
# include <iostream>

int main()
{
	std::vector<int>	v;

	v.push_back(21);
	v.push_back(42);
	v.push_back(84);
	v.push_back(168);

	try
	{
		std::cout << *easyfind(v, 42) << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "Exception: value not found!" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << *easyfind(v, 168) << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "Exception: value not found!" << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << *easyfind(v, 0) << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "Exception: value not found!" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << *easyfind(v, -128) << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "Exception: value not found!" << std::endl;
	}

	return (0);
}