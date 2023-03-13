# include "MutantStack.hpp"

# include <iostream>
# include <vector>
# include <list>

int main()
{
	{
		std::cout << ANSI_RED << "-MUTANT STACK-" << ANSI_RESET << std::endl;

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

		std::cout << "Top: " << mutant.top() << std::endl;

		MutantStack<int> tmp = mutant;

		MutantStack<int>::iterator top = tmp.end();
		MutantStack<int>::iterator bottom = tmp.begin();

		std::cout << "Values: " << std::endl;

		while (top != bottom)
		{
			top--;
			std::cout << *top << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << ANSI_RED << "-LIST-" << ANSI_RESET << std::endl;

		std::list<int> list;

		list.push_back(0);
		list.push_back(1);

		std::cout << ANSI_YELLOW << "Push: We add two elements in the stack " << ANSI_RESET << std::endl;

		std::cout << "Top: " << list.back() << std::endl;
		std::cout << "Size: " << list.size() << std::endl;

		std::cout << ANSI_YELLOW << "Pop: We remove the top element " << ANSI_RESET << std::endl;

		list.pop_back();

    	std::cout << "Top: " << list.back() << std::endl;
		std::cout << "Size: " << list.size() << std::endl;

		std::cout << ANSI_YELLOW << "Iterator: We add new elements and use the iterators to print them " << ANSI_RESET << std::endl;

		list.push_back(2);
		list.push_back(3);
		list.push_back(4);

		std::cout << "Top: " << list.back() << std::endl;

		std::list<int>::iterator top = list.end();
		std::list<int>::iterator bottom = list.begin();

		std::cout << "Values: " << std::endl;

		while (top != bottom)
		{
			top--;
			std::cout << *top << std::endl;
		}
	}

	return (0);
}

/*int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}*/
