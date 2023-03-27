#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class BitcoinExchange
{
	public:

		BitcoinExchange(void); //default constructor
		BitcoinExchange(unsigned int n); //unsigned int constructor
		BitcoinExchange(BitcoinExchange const & copy); //copy constructor
		~BitcoinExchange(void); //destructor

		BitcoinExchange	&operator=(BitcoinExchange const & rhs); //assignement operator

		void 		databaseParse(std::ifstream &databaseIfs);
		void 		inputParse(std::ifstream &inputIfs);
		void		printResult();

	private:

		std::map<std::string, double> _database;
		std::map<std::string, double> _input;
};

#endif