# include "BitcoinExchange.hpp"

# include <iostream>
# include <vector>
# include <sstream>
# include <fstream>

int main(int argc, char **argv)
{
    if (argc ==  2)
    {
        std::ifstream   inputIfs(argv[1]);
	    std::ifstream   databaseIfs("data.csv");

	    if (inputIfs.fail() || databaseIfs.fail())
        {
            std::cout << ANSI_RED << "Error: could not open file" << ANSI_RESET << std::endl;
            return (1);
        }

        BitcoinExchange btc(databaseIfs);

        btc.inputParse(inputIfs);

        inputIfs.close();
        databaseIfs.close();
        return(0);
    }
    std::cout << ANSI_RED << "Usage: " << argv[0] << "<INPUT_FILE>" << ANSI_RESET << std::endl;
    return (1);
}
