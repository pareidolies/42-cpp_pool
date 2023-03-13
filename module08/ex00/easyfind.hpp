#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <exception>
# include <iterator>

template<typename T>
typename T::iterator easyfind(T container, int toFind)
{
	typename T::iterator res = std::find(container.begin(), container.end(), toFind);

	if (res == container.end())
		throw (std::exception());
	return (res);
}

#endif