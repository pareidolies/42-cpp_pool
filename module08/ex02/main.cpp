# include "MutantStack.hpp"

# include <iostream>
# include <vector>

int main()
{
  	MutantStack<int> mutant;
	
	mutant.push(0);
	mutant.push(1);
	
	std::cout << ANSI_YELLOW << "Push: We add two elements in the stack " << ANSI_RESET << std::endl;

	std::cout << "Top: " << mutant.top() << std::endl;
	std::cout << "Size: " << mutant.size() << std::endl;
	
	std::cout << ANSI_YELLOW << "Pop: We remove the top element " << ANSI_RESET << std::endl;

	mutant.pop();

    std::cout << "Top: " << mutant.top() << std::endl;
	std::cout << "Size: " << mutant.size() << std::endl;
	
	std::cout << ANSI_YELLOW << "Iterator: We add new elements and use the iterators to print them " << ANSI_RESET << std::endl;

	mutant.push(2);
	mutant.push(3);
	mutant.push(4);
	
	MutantStack<int>::iterator begin = mutant.begin();
	MutantStack<int>::iterator end = mutant.end();
	
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}

	return (0);
}
