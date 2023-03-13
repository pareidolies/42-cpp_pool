# include "Span.hpp"

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

Span::Span(void) : _sizeMax(0)
{

}

Span::Span(unsigned int n) : _sizeMax(n) 
{

}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Span::Span(Span const & copy) : _sizeMax(copy._sizeMax), _vector(copy._vector)
{

}

Span	&Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_sizeMax = rhs._sizeMax;
		_vector = rhs._vector;
	}
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Span::~Span(void)
{

}

/******************************************************************************
*                                  GETTERS                                    *
******************************************************************************/

std::vector<int>	&Span::getVector()
{
	return (this->_vector);
}


/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void			Span::addNumber(int nbr)
{
	if (this->_vector.size() == _sizeMax)
		throw (Span::CannotAddElement());

	this->_vector.push_back(nbr);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_vector.size() == 1 || this->_vector.empty())
		throw (Span::CannotFindSpan());

	std::vector<int> tmp(_vector);
	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = UINT_MAX;
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		shortest = std::min(shortest, static_cast<unsigned int>(*(it + 1)) - (*it));
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_vector.size() == 1 || this->_vector.empty())
		throw (Span::CannotFindSpan());
	
	unsigned int max = *(std::max_element(this->_vector.begin(), this->_vector.end()));
	unsigned int min = *(std::min_element(this->_vector.begin(), this->_vector.end()));

	return (max - min);
}

void			Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	//std::cout << "distance : " << std::distance(begin, end) << std::endl;
	if (_vector.size() + std::distance(begin, end) > _sizeMax)
		throw (CannotAddElement());
	_vector.insert(_vector.begin(), begin, end);
}

void			Span::printSpan()
{
	std::cout <<"Values: ";
	for (std::vector<int>::iterator it = _vector.begin() ; it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/******************************************************************************
*                                EXCEPTIONS                                   *
******************************************************************************/

char const *	Span::CannotAddElement::what() const throw()
{
	return ("Exception: Cannot add element because the Span is full!");
}

char const *	Span::CannotFindSpan::what() const throw()
{
	return ("Exception: Cannot find Span because only one or no element in it!");
}
