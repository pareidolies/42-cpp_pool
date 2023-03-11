# include "Span.hpp"

# include <algorithm>
# include <cmath>
# include <iterator>
# include <vector>
# include <exception>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Span::Span(void) : _size(0)
{

}

Span::Span(unsigned int n) : _size(n) 
{

}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Span::Span(Span const & copy) : _size(copy._size), _vector(copy._vector)
{

}

Span	&Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_size = rhs._size;
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
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void			Span::addNumber(int nbr)
{
	if (this->_vector.size() == _size)
		throw (Span::CannotAddElement());

	this->_vector.push_back(nbr);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_vector.size() == 1 || this->_vector.empty())
		throw (Span::CannotFindSpan());

	std::vector<int> tmp(_vector);

	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = UINT_MAX;
	
	for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		shortest = std::min(shortest, static_cast<unsigned int>(*(it + 1)) - static_cast<unsigned int>(*it));
	return (shortest);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_vector.size() == 1 || this->_vector.empty())
		throw (Span::CannotFindSpan());
	
	unsigned int max = *(std::max_element(this->_vector.begin(), this->_vector.end()));
	unsigned int min = *(std::min_element(this->_vector.begin(), this->_vector.end()));
	
	return (max - min);
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