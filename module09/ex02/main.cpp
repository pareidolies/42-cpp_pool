# include "PmergeMe.hpp"

# include <iostream>
# include <vector>
# include <sstream>
# include <fstream>

int main(int argc, char **argv)
{
    if (argc ==  2 && argv[1])
    {
        PmergeMe PmergeMe = PmergeMe(argv[1]);
        try 
        {
			std::cout << PmergeMe.compute() << std::endl;
		} 
        catch (std::exception &e) 
        {
			std::cout << ANSI_RED << e.what() << ANSI_RESET <<std::endl;
        }
        return(0);
    }
    std::cout << ANSI_RED << "Usage: " << argv[0] << "<INPUT_STRING>" << ANSI_RESET << std::endl;
    return (1);
}
