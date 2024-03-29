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

BitcoinExchange::BitcoinExchange(std::ifstream &ifs)
{
	databaseParse(ifs);
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
		if (value[i] == '-')
			i++;
		if (!(isdigit(value[i]) || value[i] == '.'))
			return(false);
	}
	return(true);
}

bool			BitcoinExchange::checkDate(std::string date)
{
	std::istringstream	iss(date);
	std::string			_year, _month, _day;

	getline(iss, _year, '-');
	getline(iss, _month, '-');
	getline(iss, _day);

	if (!_year.length() || !_month.length() || !_day.length())
		return (false);

	time_t rawtime;
	struct tm * timeinfo;
	int year, month ,day;

	year = atoi(_year.c_str());
	month = atoi(_month.c_str());
	day = atoi(_day.c_str());

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	mktime (timeinfo);
	//is the normalized date still the same?
	if (timeinfo->tm_year != year - 1900 || timeinfo->tm_mon != month - 1 || timeinfo->tm_mday != day)
		return (false);

	return(true);
}

void			BitcoinExchange::findRate(std::string & date, double value)
{
	std::map<std::string, double>::iterator it = _database.lower_bound(date);
	std::map<std::string, double>::iterator itBegin = _database.begin();
			
	if (date < itBegin->first)
		std::cout << ANSI_RED << "Error: date too old : " << date << ANSI_RESET << std::endl;
	else 
	{
		if (date != it->first)
			it--;
		std::cout << date << " => " << value << " = ";
		//std::cout << std::fixed;
		//std::cout.precision(2);
		std::cout << it->second * value;
		std::cout << std::endl;
	}
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
			std::cout << ANSI_RED << "Error: bad input, missing date or value => " + line << ANSI_RESET << std::endl;
			continue;
		}

		if (date != "date")
		{
			if (!checkDate(date))
			{
				std::cout << ANSI_RED << "Error: bad input, wrong date => " + line << ANSI_RESET << std::endl;
				continue;
			}

			if (!checkValue(value))
			{
				std::cout << ANSI_RED << "Error: bad input, wrong value => " + line << ANSI_RESET << std::endl;
				continue;
			}

			double tmp = std::atof(value.c_str());
			if (tmp > 1000) 
			{
				std::cout << ANSI_RED << "Error: too large a number => " << tmp << ANSI_RESET << std::endl;
				continue;
			}
			if (tmp < 0) 
			{
				std::cout << ANSI_RED << "Error: not a positive number => " << tmp << ANSI_RESET << std::endl;
				continue;
			}

			findRate(date, tmp);
		}
	}
}
