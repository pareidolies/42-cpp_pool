#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iterator>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

template<typename T>
typename T::const_iterator easyfind(T const & container, int toFind)
{
	typename T::const_iterator res = std::find(container.begin(), container.end(), toFind);

	if (res == container.end())
		throw (std::exception());
	return (res);
}

#endif