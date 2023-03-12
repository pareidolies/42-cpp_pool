# include "iter.hpp"

# include <iostream>
# include <stddef.h>

template <typename T>
void ft_print(T const & current)
{
    std::cout << current << " ";
}

template <typename T>
void ft_increment(T const & current)
{
    std::cout << current + 1 << " ";;
}

template <typename T>
void ft_increment_char(T const & current)
{
    std::cout << (char)(current + 1) << " ";;
}

int main()
{
	int		i[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
	float	f[] = {21.21f, 42.42f, 84.84f};
	char	s[] = "Hello everyone!";

	iter<int>(i, sizeof(i) / sizeof(int), &ft_print);
	std::cout << std::endl;
	iter<int>(i, sizeof(i) / sizeof(int), &ft_increment);
	
	std::cout << std::endl;
	std::cout << std::endl;

	iter<float>(f, sizeof(f) / sizeof(float), &ft_print);
	std::cout << std::endl;
	iter<float>(f, sizeof(f) / sizeof(float), &ft_increment);
	
	std::cout << std::endl;
	std::cout << std::endl;

	iter<char>(s, sizeof(s), ft_print);
	std::cout << std::endl;
	iter<char>(s, sizeof(s), ft_increment_char);

	return 0;
}

/*class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];
iter( tab, 5, print );
iter( tab2, 5, print );
return 0;
}*/
