# include "PmergeMe.hpp"

# include <iostream>

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

PmergeMe::PmergeMe(std::deque<int> deque) : _unsortedVector(0), 
										    _unsortedDeque(deque)
{
	fordJohnsonSort(deque);
}

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
	int									pos;
	size_t								stop;

	createPairs(vectorPair);
	sortPairsRecursively(vectorPair, vectorPair.size()); //use recursive merge

	addFirstHalf(vectorPair, sortedVector);
	size = vectorPair.size();
	addElementPairedWithFirst(vectorPair, sortedVector);
	
	pos = binarySearch(vectorPair[0].second, sortedVector, vectorPair[0].first);
	sortedVector.insert(sortedVector.begin() + pos, vectorPair[0].second);

	jacobsthal[0] = 1;
	jacobsthal[1] = 1;
	jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
	stop = 0;
	
	//int check = 0;

	while (1)
	{
		stop = (jacobsthal[2] < size) ? jacobsthal[2] : size - 1;
		for (size_t i = (jacobsthal[2] < size) ? jacobsthal[2] : size - 1; i > jacobsthal[1] && i < size && i >= 0; i--)
		{
			pos = binarySearch(vectorPair[i - 1].second, sortedVector, vectorPair[i - 1].first);
			sortedVector.insert(sortedVector.begin() + pos, vectorPair[i - 1].second);
			//std::cout <<ANSI_BLUE << check << ANSI_RESET << std::endl;
		}
		if (stop == size - 1)
			break;
		jacobsthal[0] = jacobsthal[1];
		jacobsthal[1] = jacobsthal[2];
		jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
		//check++;
	}

	if (unsortedVector.size() % 2 == 1)
	{
		pos = binarySearch(*(unsortedVector.end() - 1), sortedVector, -1);
		sortedVector.insert(sortedVector.begin() + pos, *(unsortedVector.end() - 1));
	}

	printBefore(unsortedVector);
	printAfter(sortedVector);
	isSorted(sortedVector);
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
}

void	PmergeMe::sortPairsRecursively(std::vector < std::pair<int,int> > & vectorPair, size_t size)
{
	//std::pair<int,int> tmp;

	if (size == 1)
		return;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (vectorPair[i].first > vectorPair[i + 1].first)
			std::swap(vectorPair[i], vectorPair[i + 1]);
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

int		PmergeMe::binarySearch(int value, std::vector<int> sortedVector, int first)
{
	int	low = 0;
	int high;
	if (first == -1)
		high = sortedVector.size() - 1;
	else
		high = lower_bound(sortedVector.begin(), sortedVector.end(), first) - sortedVector.begin();

	std::cout << ANSI_BLUE << "HIGH : " << high << "for: " << value << "first: " << first << ANSI_RESET << std::endl;

	while (low <= high) 
	{
        int mid = low + (high - low) / 2;

		if (mid == 0)
		{
			if (value < sortedVector[0])
				return (0);
			else
				return (1);
		}
		if (mid == static_cast<int>(sortedVector.size() - 1))
		{
			if (value > sortedVector.back())
				return (sortedVector.size());
			else
				return (sortedVector.size() - 1);
		}
        if (value >= sortedVector[mid - 1] && value <= sortedVector[mid])
		{
			if (first == -1)
				std::cout << ANSI_GREEN << "mid:" << mid << ANSI_RESET << std::endl;
            return (mid);
		}
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

void	PmergeMe::isSorted(std::vector<int> & vector)
{
	size_t size = vector.size() - 1;

	for(size_t i = 0; i < size - 1; i++)
	{
		if (vector[i] > vector [i + 1])
			std::cout << ANSI_RED << "Oups... Vector not sorted at: " << vector[i] << ANSI_RESET << std::endl;
	}
	std::cout << ANSI_GREEN << "Vector of size " << vector.size() << " sorted!" << ANSI_RESET << std::endl;

}

/******************************************************************************
*                           DEQUE MEMBER FUNCTIONS                            *
******************************************************************************/

void	PmergeMe::fordJohnsonSort(std::deque<int> unsortedDeque)
{
	std::deque<int>						sortedDeque;
	std::deque < std::pair<int,int> >	dequePair;
	size_t								jacobsthal[3];
	size_t								size;	
	int									pos;
	size_t								stop;

	createPairs(dequePair);
	sortPairsRecursively(dequePair, dequePair.size());

	addFirstHalf(dequePair, sortedDeque);
	size = dequePair.size();
	addElementPairedWithFirst(dequePair, sortedDeque);
	
	pos = binarySearch(dequePair[0].second, sortedDeque);
	sortedDeque.insert(sortedDeque.begin() + pos, dequePair[0].second);

	jacobsthal[0] = 1;
	jacobsthal[1] = 1;
	jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
	stop = 0;
	
	while (1)
	{
		stop = (jacobsthal[2] < size) ? jacobsthal[2] : size - 1;
		for (size_t i = (jacobsthal[2] < size) ? jacobsthal[2] : size - 1; i > jacobsthal[1] && i < size && i >= 0; i--)
		{
			/*if (dequePair[i - 1].second < sortedDeque.front())
			{
				std::cout << ANSI_RED << "coucou" << ANSI_RESET << std::endl;
				sortedDeque.push_front(dequePair[i - 1].second);
			}
			if (dequePair[i - 1].second > sortedDeque.front() && dequePair[i - 1].second < sortedDeque[1])
			{
				std::cout << ANSI_RED << "coucou" << ANSI_RESET << std::endl;
				sortedDeque.push_front(dequePair[i - 1].second);
				std::swap(sortedDeque[0], sortedDeque[1]);
			}
			else if (dequePair[i - 1].second > sortedDeque.back())
				sortedDeque.push_back(dequePair[i - 1].second);
			else
			{*/
				pos = binarySearch(dequePair[i - 1].second, sortedDeque);
				sortedDeque.insert(sortedDeque.begin() + pos, dequePair[i - 1].second);
			//}
		}
		if (stop == size - 1)
			break;
		jacobsthal[0] = jacobsthal[1];
		jacobsthal[1] = jacobsthal[2];
		jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
	}

	if (unsortedDeque.size() % 2 == 1)
	{
		pos = binarySearch(*(unsortedDeque.end() - 1), sortedDeque);
		sortedDeque.push_front (*(unsortedDeque.end() - 1));
	}

	printBefore(unsortedDeque);
	printAfter(sortedDeque);
}

void	PmergeMe::createPairs(std::deque < std::pair<int,int> > & dequePair)
{
	size_t size = _unsortedDeque.size();

	for(size_t i = 0; i < size - 1; i+=2)
	{
		if (_unsortedDeque[i] >_unsortedDeque[i+1])
			dequePair.push_back(std::make_pair(_unsortedDeque[i],_unsortedDeque[i+1]));
		else
			dequePair.push_back(std::make_pair(_unsortedDeque[i+1],_unsortedDeque[i]));
	}
}

void	PmergeMe::sortPairsRecursively(std::deque < std::pair<int,int> > & dequePair, size_t size)
{
	std::pair<int,int> tmp;

	if (size == 1)
		return;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (dequePair[i].first > dequePair[i + 1].first)
		{
			//std::swap(dequePair[i].first, dequePair[i+1].first);
			tmp = dequePair[i];
			dequePair[i] = dequePair[i + 1];
			dequePair[i + 1] = tmp;
		}
   }
   sortPairsRecursively(dequePair, size - 1);
}

void	PmergeMe::addFirstHalf(std::deque < std::pair<int,int> > & dequePair, std::deque<int> & sortedDeque)
{
	size_t size = dequePair.size();

	for(size_t i = 0; i < size; i++)
		sortedDeque.push_back(dequePair[i].first);
}

void	PmergeMe::addElementPairedWithFirst(std::deque < std::pair<int,int> > & dequePair, std::deque<int> & sortedDeque)
{
	sortedDeque.push_front(dequePair[0].second);
	dequePair.erase(dequePair.begin());
}

int		PmergeMe::binarySearch(int value, std::deque<int> sortedDeque)
{
	int	low = 0;
	int	high = sortedDeque.size();

	while (low <= high) 
	{
        int mid = low + (high - low) / 2;

		if (mid == 0)
			return (mid);
        if (value >= sortedDeque[mid - 1] && value <= sortedDeque[mid])
            return (mid);
        if (value > sortedDeque[mid])
            low = mid + 1;
        if (value < sortedDeque[mid])
            high = mid - 1;
    }
	return(0);
}

void	PmergeMe::printBefore(std::deque<int> & deque)
{
	size_t size = deque.size();

	std::cout << ANSI_PURPLE << "Before: ";
	for(size_t i = 0; i < size; i++)
		std::cout << deque[i] << " ";
	std::cout << ANSI_RESET << std::endl;

}

void	PmergeMe::printAfter(std::deque<int> & deque)
{
	size_t size = deque.size();

	std::cout << ANSI_YELLOW << "After: ";
	for(size_t i = 0; i < size; i++)
		std::cout << deque[i] << " ";
	std::cout << ANSI_RESET << std::endl;

}
