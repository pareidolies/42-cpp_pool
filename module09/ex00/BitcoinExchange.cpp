# include "BitcoinExchange.hpp"

# include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>


/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(unsigned int n)
{

}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy) : _database(copy._database)
{

}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		_database = rhs._database;
	}
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

BitcoinExchange::~BitcoinExchange(void)
{

}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void			BitcoinExchange::databaseParse(std::ifstream &ifs)
{
	std::string line;

	while (getline(ifs, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string rate;

		getline(ss, date, ',');
		getline(ss, rate);
		if (date != "date") 
			_database[date] = std::atof(rate.c_str());
	}
}

bool			BitcoinExchange::checkValue(std::string value)
{
	for(int i = 0; i < static_cast<int>(value.length()); ++i) 
	{
		if (!(isdigit(value[i]) || value[i] == '.'))
			return(false);
	}
	return(true);
}

bool			BitcoinExchange::checkDate(std::string date)
{
	time_t rawtime;
	struct tm * timeinfo;
	int year, month ,day;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	if (mktime (timeinfo) == -1)
		return (false);

	return(true);
}

void			BitcoinExchange::inputParse(std::ifstream &ifs)
{
	std::string line;

	while (getline(ifs, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;

		getline(ss, date, '|');
		date.erase(remove_if(date.begin(), date.end(), isspace), date.end());
		getline(ss, value);
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());

		if (!date.length() || !value.length()) {
			std::cout << ANSI_RED << "Error: bad input => " + line << ANSI_RESET << std::endl;
			continue;
		}
		if (date != "date")
		{
			if (!checkDate(date) || !checkValue(value))
				std::cout << ANSI_RED << "Error: bad input => " + line << ANSI_RESET << std::endl;
			double tmp = std::atof(value.c_str());
			if (tmp > 1000) 
			{
				std::cout << ANSI_RED << "Error: too large a number" << ANSI_RESET << std::endl;
				continue;
			}
			if (tmp < 0) 
			{
				std::cout << ANSI_RED << "Error: not a positive number" << ANSI_RESET << std::endl;
				continue;
			}

			std::map<std::string, double>::iterator it = _database.find(date);
			double rate = (it != _database.end() ? _database[date] : findClosestRate(date, _database));
			double res = tmp * rate;

			std::cout << date << " => " << tmp << " = " << res << std::endl;
		}
	}
}
