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
	std::vector<int>					sortedVector;
	std::vector < std::pair<int,int> >	vectorPair;
	size_t								jacobsthal[3];
	size_t								size;	
	//size_t									shift;
	int									pos;
	size_t								stop;

	createPairs(vectorPair);
	sortPairsRecursively(vectorPair, vectorPair.size());
	addFirstHalf(vectorPair, sortedVector);

	size = vectorPair.size();

	printBefore(unsortedVector);
	printAfter(sortedVector);

	addElementPairedWithFirst(vectorPair, sortedVector);

	printBefore(unsortedVector);
	printAfter(sortedVector);
	
	pos = binarySearch(vectorPair[0].second, sortedVector);
	sortedVector.insert(sortedVector.begin() + pos, vectorPair[0].second);
	//vectorPair.erase(vectorPair.begin());

	printBefore(unsortedVector);
	printAfter(sortedVector);

	jacobsthal[0] = 1;
	jacobsthal[1] = 1;
	jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
	//shift = 2;
	stop = 0;
	
	while (1)
	{
		stop = (jacobsthal[2] < size) ? jacobsthal[2] : size - 1;
		for (size_t i = (jacobsthal[2] < size) ? jacobsthal[2] : size - 1; i > jacobsthal[1] && i < size && i >= 0; i--)
		{
			std::cout << "to sort: " << vectorPair[i - 1].second << std::endl;
			pos = binarySearch(vectorPair[i - 1].second, sortedVector);
			sortedVector.insert(sortedVector.begin() + pos, vectorPair[i - 1].second);
			//vectorPair.erase(vectorPair.begin() + (i - shift));
			//shift++;	
			std::cout << "jacob: " << i << std::endl;
		}
		if (stop == size - 1)
			break;
		jacobsthal[0] = jacobsthal[1];
		jacobsthal[1] = jacobsthal[2];
		jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
	}

	if (unsortedVector.size() % 2 == 1)
	{
		//std::cout << "last: " << unsortedVector[unsortedVector.size() - 1] << std::endl;
		pos = binarySearch(*(unsortedVector.end() - 1), sortedVector);
		sortedVector.insert(sortedVector.begin() + pos, *(unsortedVector.end() - 1));
	}

	printBefore(unsortedVector);
	printAfter(sortedVector);

}

void	PmergeMe::createPairs(std::vector < std::pair<int,int> > & vectorPair)
{
	size_t size = _unsortedVector.size();

	for(size_t i = 0; i < size - 1; i+=2)
	{
		if (_unsortedVector[i] >_unsortedVector[i+1])
			vectorPair.push_back(std::make_pair(_unsortedVector[i],_unsortedVector[i+1]));
		else
			vectorPair.push_back(std::make_pair(_unsortedVector[i+1],_unsortedVector[i]));
	}
	std::cout << "size:" << vectorPair.size() << std::endl;
}

void	PmergeMe::sortPairsRecursively(std::vector < std::pair<int,int> > & vectorPair, size_t size)
{
	std::pair<int,int> tmp;

	if (size == 1)
		return;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (vectorPair[i].first > vectorPair[i + 1].first)
		{
			tmp = vectorPair[i];
			vectorPair[i] = vectorPair[i + 1];
			vectorPair[i + 1] = tmp;
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

void	PmergeMe::addElementPairedWithFirst(std::vector < std::pair<int,int> > & vectorPair, std::vector<int> & sortedVector)
{
	sortedVector.insert(sortedVector.begin(), vectorPair[0].second);
	vectorPair.erase(vectorPair.begin());
}

int		PmergeMe::binarySearch(int value, std::vector<int> sortedVector)
{
	int	low = 0;
	int	high = sortedVector.size();

	while (low <= high) 
	{
        int mid = low + (high - low) / 2;

		if (mid == 1)
		{
			if (value > sortedVector[mid])
				return (mid);
			else
				return (mid - 1);
		}
        if (value >= sortedVector[mid - 1] && value <= sortedVector[mid])
            return (mid);
        if (value > sortedVector[mid])
            low = mid + 1;
        if (value < sortedVector[mid])
            high = mid - 1;
    }
	return(0);
}

void	PmergeMe::printBefore(std::vector<int> & vector)
{
	size_t size = vector.size();

	std::cout << ANSI_PURPLE << "Before: ";
	for(size_t i = 0; i < size; i++)
		std::cout << vector[i] << " ";
	std::cout << ANSI_RESET << std::endl;

}

void	PmergeMe::printAfter(std::vector<int> & vector)
{
	size_t size = vector.size();

	std::cout << ANSI_YELLOW << "After: ";
	for(size_t i = 0; i < size; i++)
		std::cout << vector[i] << " ";
	std::cout << ANSI_RESET << std::endl;

}


/******************************************************************************
*                           DEQUE MEMBER FUNCTIONS                            *
******************************************************************************/
