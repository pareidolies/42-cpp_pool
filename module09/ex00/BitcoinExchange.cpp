# include "BitcoinExchange.hpp"

# include <algorithm>
# include <cmath>
# include <iterator>
# include <vector>
# include <exception>
# include <limits.h>
# include <iostream>


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

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy) : _data(copy._data)
{

}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		_data = rhs._data;
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

void			BitcoinExchange::addNumber(int nbr)
{
	if (this->_vector.size() == _sizeMax)
		throw (BitcoinExchange::CannotAddElement());

	this->_vector.push_back(nbr);
}

unsigned int	BitcoinExchange::shortestBitcoinExchange(void) const
{
	if (this->_vector.size() == 1 || this->_vector.empty())
		throw (BitcoinExchange::CannotFindBitcoinExchange());

	std::vector<int> tmp(_vector);
	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = UINT_MAX;
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		shortest = std::min(shortest, static_cast<unsigned int>(*(it + 1)) - (*it));
	return (shortest);
}

unsigned int	BitcoinExchange::longestBitcoinExchange(void) const
{
	if (this->_vector.size() == 1 || this->_vector.empty())
		throw (BitcoinExchange::CannotFindBitcoinExchange());
	
	unsigned int max = *(std::max_element(this->_vector.begin(), this->_vector.end()));
	unsigned int min = *(std::min_element(this->_vector.begin(), this->_vector.end()));

	return (max - min);
}

void			BitcoinExchange::fillBitcoinExchange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) > _sizeMax)
		throw (CannotAddElement());
	_vector.insert(_vector.begin(), begin, end);
}

void			BitcoinExchange::printBitcoinExchange()
{
	std::cout <<"Values: ";
	for (std::vector<int>::iterator it = _vector.begin() ; it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
