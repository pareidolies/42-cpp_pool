# include "iter.hpp"

# include <iostream>
# include <stddef.h>

template <typename T>
void ft_print(T & current)
{
    std::cout << current << " ";
}

template <typename T>
void ft_increment(T & current)
{
    current++;
}

int main()
{
	int		i[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
	float	f[] = {21.21f, 42.42f, 84.84f};
	char	s[] = "Hello everyone!";

	iter<int>(i, sizeof(i) / sizeof(int), &ft_print);
	iter<int>(i, sizeof(i) / sizeof(int), &ft_increment);
	std::cout << std::endl;
	iter<int>(i, sizeof(i) / sizeof(int), &ft_print);
	
	std::cout << std::endl;
	std::cout << std::endl;

	iter<float>(f, sizeof(f) / sizeof(float), &ft_print);
	iter<float>(f, sizeof(f) / sizeof(float), &ft_increment);
	std::cout << std::endl;
	iter<float>(f, sizeof(f) / sizeof(float), &ft_print);
	
	std::cout << std::endl;
	std::cout << std::endl;

	iter<char>(s, sizeof(s), ft_print);
	iter<char>(s, sizeof(s), ft_increment);
	std::cout << std::endl;
	iter<char>(s, sizeof(s), ft_print);
	
	return 0;
}
