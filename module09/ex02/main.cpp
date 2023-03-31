# include "PmergeMe.hpp"

# include <iostream>
# include <vector>
# include <sstream>
# include <fstream>
# include <string>
# include <ctime>


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
    if (argc < 2 )
    {
        std::cout << ANSI_RED << "Usage: " << argv[0] << "<NBRS TO SORT>" << ANSI_RESET << std::endl;
        return (1);
    }

    if (!checkArgs(argc, argv) || !checkDuplicates(argc, argv))
    {
        std::cout << ANSI_RED << "Error: Wrong args" << ANSI_RESET << std::endl;
        return (1);
    }
    
    std::vector<int>    unsortedVector;
    std::deque<int>     unsortedDeque;
    clock_t             start, end;
    double              time;

    start = clock();
    for(int i = 1; i < argc; i++)
        unsortedVector.push_back(atoi(argv[i]));
    PmergeMe vector(unsortedVector);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << ANSI_BLUE << "Time to process a range of : " << unsortedVector.size() << " elements with std::vector : "
	            << time << " us" << std::endl;

    /*start = clock();
    for(int i = 1; i < argc; i++)
        unsortedDeque.push_back(atoi(argv[i]));
    PmergeMe deque(unsortedDeque);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of : " << unsortedDeque.size() << " elements with std::deque : "
	            << time << " us" << ANSI_RESET << std::endl;*/

	return(0);    
}
