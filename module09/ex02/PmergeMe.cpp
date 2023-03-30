# include "PmergeMe.hpp"

#include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(std::vector<int> vector) : _unsortedVector(vector), 
											  _unsortedDeque(0)
{
	fordJohnsonSort(vector);
}

//PmergeMe::PmergeMe(std::deque<int> deque) : _unsortedVector(0), 
											//  _unsortedDeque(deque)
//{
//	fordJohnsonSort(deque);
//}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PmergeMe::PmergeMe(PmergeMe const & copy) : _unsortedVector(copy._unsortedVector), 
											_unsortedDeque(copy._unsortedDeque)
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
	sortPairsRecursively(vectorPair, vectorPair.size());
	addFirstHalf(vectorPair, sortedVector);
	print(unsortedVector);
	print(sortedVector);
}

void	PmergeMe::createPairs(std::vector < std::pair<int,int> > & vectorPair)
{
	size_t size = _unsortedVector.size();

	for(size_t i = 0; i < size - 1; i+=2)
	{
		if (_unsortedVector[i] <_unsortedVector[i+1])
			vectorPair.push_back(std::make_pair(_unsortedVector[i],_unsortedVector[i+1]));
		else
			vectorPair.push_back(std::make_pair(_unsortedVector[i+1],_unsortedVector[i]));
	}
}

void	PmergeMe::sortPairsRecursively(std::vector < std::pair<int,int> > & vectorPair, size_t size)
{
	int tmp;

	if (size == 1)
		return;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (vectorPair[i].first > vectorPair[i + 1].first)
		{
			tmp = vectorPair[i].first;
			vectorPair[i].first = vectorPair[i + 1].first;
			vectorPair[i + 1].first = tmp;
		}
   }
   sortPairsRecursively(vectorPair, size - 1);
}


void	PmergeMe::addFirstHalf(std::vector < std::pair<int,int> > & vectorPair, std::vector<int> & sortedVector)
{
	size_t size = vectorPair.size();

	for(size_t i = 0; i < size; i++)
		sortedVector.push_back(vectorPair[i].first);
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

/******************************************************************************
*                           DEQUE MEMBER FUNCTIONS                            *
******************************************************************************/
