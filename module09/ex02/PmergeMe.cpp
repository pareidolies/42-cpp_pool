# include "PmergeMe.hpp"

#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(std::vector<int> unsortedVector) : _unsortedVector(unsortedVector), _unsortedDeque(0)
{
	fordJohnsonSort(unsortedVector);
}

PmergeMe::PmergeMe(std::deque<int> unsortedDeque) : _unsortedVector(0), _unsortedDeque(unsortedDeque)
{
	fordJohnsonSort(unsortedDeque);
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PmergeMe::PmergeMe(PmergeMe const & copy) : _unsortedVector(copy._unsortedVector), _unsortedDeque(copy._unsortedDeque)
{

}

PmergeMe	&PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		_unsortedVector = rhs._unsortedVector;
		_unsortedDeque = rhs._unsortedDeque;
	}
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

PmergeMe::~PmergeMe(void)
{

}

/******************************************************************************
*                          VECTOR MEMBER FUNCTIONS                            *
******************************************************************************/

void	PmergeMe::fordJohnsonSort(std::vector<int> unsortedVector)
{
	std::vector<int> sortedVector;
	std::vector < std::pair<int,int> > vectorPair;

	createPairs(vectorPair);
	sortPairs(vectorPair);

}


void	PmergeMe::createPairs(std::vector < std::pair<int,int> > & vectorPair)
{

}


void	PmergeMe::sortPairs(std::vector < std::pair<int,int> > & vectorPair)
{

}


void	PmergeMe::merge()
{

}

void	PmergeMe::binarySearch()
{

}

void	PmergeMe::insertAtPosition()
{

}

void	PmergeMe::print(std::vector<int> & vector)
{
	size_t size = vector.size();

	std::cout << ANSI_PURPLE << "Before: ";
	for(size_t i = 0; i < size; i++)
		std::cout << vector[i] << " ";
	std::cout << ANSI_RESET << std::endl;

}
