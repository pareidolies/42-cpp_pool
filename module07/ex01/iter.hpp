#ifndef ITER_HPP
# define ITER_HPP

# include <stddef.h>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

template <typename T>
void iter(T *tab, size_t size, void (f)(const T &))
{
	if (!tab || !f)
		return ;
	for (size_t i = 0; i < size; i++)
		f(tab[i]);
}

#endif