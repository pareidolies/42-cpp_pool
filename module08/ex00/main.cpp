# include "easyfind.hpp"

# include <vector>
# include <deque>
# include <iostream>

int main(void)
{
	std::vector<int>	v (4, 0);

		v[0] = 21;
		v[1] = 42;
		v[2] = 84;
		v[3] = 168;
		try
		{
			std::cout << *easyfind(v, 42) << '\n';
		}
		catch (std::exception const & e)
		{
			std::cout << "Exception: value not found!" << '\n';
		}

		try
		{
			std::cout << *easyfind(v, 0) << '\n';
		}
		catch (std::exception const & e)
		{
			std::cout << "Exception: value not found!" << '\n';
		}
		return (0);
}
