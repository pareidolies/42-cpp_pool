# include "Array.hpp"

# include <iostream>
# include <stddef.h>

# define MAX_VAL 750

int main(void)
{
	//My own main.c
	{
		std::cout << ANSI_BLUE << "-My own main.c-" << ANSI_RESET << std::endl << std::endl;

		Array<int> empty;
		Array<int> fibonacci(9);
		Array<int> fortytwo(2);

		std::cout << "Trying to print empty array:" << std::endl;

		try 
		{
			std::cout << empty[0] << std::endl;
		} 
		catch (std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		fibonacci[0] = 0;
		fibonacci[1] = 1;
		for (unsigned int i = 2; i < fibonacci.size(); i++)
			fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

		std::cout << "Fibonacci array:" << std::endl;
		for (unsigned int i = 0; i < fibonacci.size(); i++)
			std::cout << fibonacci[i] << " ";
		
		std::cout << std::endl;

		std::cout << "Size: " << fibonacci.size() << std::endl;

		fortytwo[0] = 21;
		fortytwo[1] = 42;
		fibonacci = fortytwo;

		std::cout << std::endl;

		std::cout << "Fortytwo array:" << std::endl;
		for (unsigned int i = 0; i < fortytwo.size(); i++)
			std::cout << fortytwo[i] << " ";

		std::cout << std::endl;
		
		std::cout << "Size: " << fortytwo.size() << std::endl;
		
		std::cout << std::endl;

		std::cout << "Fibonacci array becomes fortytwo array:" << std::endl;
		for (unsigned int i = 0; i < fibonacci.size(); i++)
			std::cout << fibonacci[i] << " ";
		
		std::cout << std::endl;
		std::cout << "Size: " << fibonacci.size() << std::endl;
		std::cout << std::endl;

		std::cout << "Try & catch:" << std::endl;
		try 
		{
			fibonacci[0] = 0;
			std::cout << fibonacci[0] << std::endl;
			fibonacci[1] = 1;
			std::cout << fibonacci[1] << std::endl;
			fibonacci[2] = 1;
			std::cout << fibonacci[2] << std::endl;
		} 
		catch (std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "New fibonacci array:" << std::endl;
		for (unsigned int i = 0; i < fibonacci.size(); i++)
			std::cout << fibonacci[i] << " ";

		std::cout << std::endl;
		std::cout << "Size: " << fibonacci.size() << std::endl;
		std::cout << std::endl;

		std::cout << "Fortytwo array (did it change?):" << std::endl;
		for (unsigned int i = 0; i < fortytwo.size(); i++)
			std::cout << fortytwo[i] << " ";

		std::cout << std::endl;
		std::cout << "Size: " << fortytwo.size() << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//Main.c provided by 42
	{
		std::cout << ANSI_BLUE << "-Main.c provided by 42-" << ANSI_RESET << std::endl << std::endl;

		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	return (0);
}