# include "PmergeMe.hpp"

# include <iostream>
# include <vector>
# include <sstream>
# include <fstream>
# include <string>
# include <ctime>
# include <cstdlib>


bool    checkArgs(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        for(int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cout << ANSI_RED << "Error: Non digit characters not allowed" << ANSI_RESET << std::endl;
                return (false);
            }
        }
        if (std::atol(argv[i]) < 0 || std::atol(argv[i]) > 2147483647)
        {
            std::cout << ANSI_RED << "Error: Only positive integers inferior to INT_MAX allowed" << ANSI_RESET << std::endl;
            return(false);
        }
    }
    return (true);
}

bool    checkDuplicates(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        for(int j = i + 1; j < argc; j++)
        {
            if (std::atol(argv[i]) == std::atol(argv[j]))
            {
                std::cout << ANSI_RED << "Error: Duplicates not allowed" << ANSI_RESET << std::endl;
                return (false);
            }
        }
    }
    return (true);
}

int main(int argc, char **argv)
{
    (void) argv;
    if (argc < 2 )
    {
        std::cout << ANSI_RED << "Usage: " << argv[0] << " <NBRS TO SORT>" << ANSI_RESET << std::endl;
        return (1);
    }

    if (!checkArgs(argc, argv) || !checkDuplicates(argc, argv))
        return (1);
    
    std::vector<int>    unsortedVector;
    std::deque<int>     unsortedDeque;
    clock_t             start, end;
    double              time;

    start = clock();
    for(int i = 1; i < argc; i++)
        unsortedVector.push_back(std::atoi(argv[i]));
    PmergeMe vector(unsortedVector);
    end = clock();
    time = static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;

	std::cout << ANSI_BLUE << "Time to process a range of : " << unsortedVector.size() << " elements with std::vector : "
	            << time << " us" << std::endl;

    /*start = clock();
    for(int i = 1; i < argc; i++)
        unsortedDeque.push_back(std::atoi(argv[i]));
    PmergeMe deque(unsortedDeque);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of : " << unsortedDeque.size() << " elements with std::deque : "
	            << time << " us" << ANSI_RESET << std::endl;*/

	return(0);    
}
