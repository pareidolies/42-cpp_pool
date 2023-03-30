# include "PmergeMe.hpp"

# include <iostream>
# include <vector>
# include <sstream>
# include <fstream>
# include <string>

bool    checkArgs(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        for(int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                return (false);
        }
        if (atol(argv[i]) < 0 || atol(argv[i]) > 2147483647)
            return(false);
    }
    return (true);
}

bool    checkDuplicates(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        for(int j = i + 1; j < argc; j++)
        {
            if (atol(argv[i]) == atol(argv[j]))
                return (false);
        }
    }
    return (true);
}

int main(int argc, char **argv)
{
    std::vector<int>    unsortedVector;
    std::deque<int>     unsortedDeque;

    if (argc < 2 )
    {
        std::cout << ANSI_RED << "Usage: " << argv[0] << "<NBRS TO SORT>" << ANSI_RESET << std::endl;
        return (1);
    }

    if (!checkArgs(argc, argv) || !checkDuplicates(argc, argv))
        return (1);
    
    for(int i = 1; i < argc; i++)
        unsortedVector.push_back(atoi(argv[i]));
    
    for(int i = 1; i < argc; i++)
        unsortedDeque.push_back(atoi(argv[i]));
    
    PmergeMe vector(unsortedVector);
    
    //PmergeMe deque(&unsortedDeque);
    //deque.fordJohnsonSort();

	return(0);    
}