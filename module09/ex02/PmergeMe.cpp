# include "PmergeMe.hpp"

# include <iostream>

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(std::vector<int> vector)
{
	fordJohnsonSort(vector);
}

/*PmergeMe::PmergeMe(std::deque<int> deque)
{
	fordJohnsonSort(deque);
}*/

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	(void) copy;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{

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

void	PmergeMe::fordJohnsonSort(std::vector<int> _unsorted)
{
	std::vector<int>					_sorted;
	std::vector < std::pair<int,int> >	_pair;
	size_t								size;
	size_t								pos;


	if (_unsorted.size() == 1 || isSorted(_unsorted))
	{
		printBefore(_unsorted);
		printAfter(_unsorted);
		return;
	}

	createPairs(_pair, _unsorted);
	recursiveSort(_pair); //use recursive merge

	addFirstHalf(_pair, _sorted);
	//std::cout << "size :" << _sorted.size() << std::endl;
	size = _pair.size();
	addElementPairedWithFirst(_pair, _sorted);
	//std::cout << "size :" << _sorted.size() << std::endl;
	
	if (_unsorted.size() > 3)
	{
		insertSecondHalf(_pair, _sorted, size);
	}
	

	if (_unsorted.size() % 2 == 1)
	{
		pos = binarySearch(*(_unsorted.end() - 1), _sorted, -1);
		_sorted.insert(_sorted.begin() + pos, *(_unsorted.end() - 1));
	}

	printBefore(_unsorted);
	printAfter(_sorted);
	if (!isSorted(_sorted))
		std::cout << ANSI_RED << "Oups... Vector not sorted" << ANSI_RESET << std::endl;
	else
		std::cout << ANSI_GREEN << "Vector of size " << _sorted.size() << " sorted!" << ANSI_RESET << std::endl;

}

void	PmergeMe::createPairs(std::vector < std::pair<int,int> > & _pair, std::vector<int> _unsorted)
{
	size_t size = _unsorted.size();

	for(size_t i = 0; i < size - 1; i+=2)
	{
		if (_unsorted[i] >_unsorted[i+1])
			_pair.push_back(std::make_pair(_unsorted[i],_unsorted[i+1]));
		else
			_pair.push_back(std::make_pair(_unsorted[i+1],_unsorted[i]));
	}
	// for(size_t i = 0; i < _pair.size(); i++)
	// {
	// 	std::cout << _pair[i].first << " " << _pair[i].second << std::endl;
	// }
}

void	PmergeMe::mergeSort(std::vector < std::pair<int,int> > & left, std::vector < std::pair<int,int> > & right, std::vector < std::pair<int,int> > & _pair)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j].first < right[k].first) 
		{
            _pair[i] = left[j];
            j++;
        }
        else 
		{
            _pair[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) 
	{
        _pair[i] = left[j];
        j++; i++;
    }
    while (k < nR) 
	{
        _pair[i] = right[k];
        k++; i++;
    }
}

void	PmergeMe::recursiveSort(std::vector < std::pair<int,int> > & _pair) 
{
    if (_pair.size() <= 1) 
		return;

    size_t mid = _pair.size() / 2;
    
	std::vector < std::pair<int,int> > left;
	std::vector < std::pair<int,int> > right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(_pair[j]);
    for (size_t j = 0; j < (_pair.size()) - mid; j++)
        right.push_back(_pair[mid + j]);

    recursiveSort(left);
    recursiveSort(right);
    mergeSort(left, right, _pair);
}

void	PmergeMe::sortPairsRecursively(std::vector < std::pair<int,int> > & _pair, size_t size)
{
	if (size == 1)
		return;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (_pair[i].first > _pair[i + 1].first)
			std::swap(_pair[i], _pair[i + 1]);
   }
   sortPairsRecursively(_pair, size - 1);
}
 
void	PmergeMe::addFirstHalf(std::vector < std::pair<int,int> > & _pair, std::vector<int> & _sorted)
{
	size_t size = _pair.size();

	for(size_t i = 0; i < size; i++)
		_sorted.push_back(_pair[i].first);
}

void	PmergeMe::addElementPairedWithFirst(std::vector < std::pair<int,int> > & _pair, std::vector<int> & _sorted)
{
	_sorted.insert(_sorted.begin(), _pair[0].second);
	_pair.erase(_pair.begin());
}

int		PmergeMe::binarySearch(int value, std::vector<int> _sorted, int first)
{
	int	low = 0;
	int high;
	if (first == -1)
		high = _sorted.size() - 1;
	else
		high = lower_bound(_sorted.begin(), _sorted.end(), first) - _sorted.begin();

	//std::cout << ANSI_BLUE << "HIGH : " << high << "for: " << value << "first: " << first << ANSI_RESET << std::endl;

	while (low <= high) 
	{
        int mid = low + (high - low) / 2;

		if (mid == 0)
		{
			if (value < _sorted[0])
				return (0);
			else
				return (1);
		}
		if (mid == static_cast<int>(_sorted.size() - 1))
		{
			if (value > _sorted.back())
				return (_sorted.size());
			else
				return (_sorted.size() - 1);
		}
        if (value >= _sorted[mid - 1] && value <= _sorted[mid])
		{
			//if (first == -1)
			//	std::cout << ANSI_GREEN << "mid:" << mid << ANSI_RESET << std::endl;
            return (mid);
		}
        if (value > _sorted[mid])
            low = mid + 1;
        if (value < _sorted[mid])
            high = mid - 1;
    }
	return(0);
}

void		PmergeMe::insertSecondHalf(std::vector < std::pair<int,int> > & _pair, std::vector<int> & _sorted, size_t size)
{
	size_t			jacobsthal[3];
	int				pos;
	size_t			stop;

	pos = binarySearch(_pair[0].second, _sorted, _pair[0].first);
	_sorted.insert(_sorted.begin() + pos, _pair[0].second);

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
			pos = binarySearch(_pair[i - 1].second, _sorted, _pair[i - 1].first);
			_sorted.insert(_sorted.begin() + pos, _pair[i - 1].second);
			//std::cout <<ANSI_BLUE << check << ANSI_RESET << std::endl;
		}
		if (stop == size - 1)
			break;
		jacobsthal[0] = jacobsthal[1];
		jacobsthal[1] = jacobsthal[2];
		jacobsthal[2] = 2 * jacobsthal[0] + jacobsthal[1];
		//check++;
	}

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

bool	PmergeMe::isSorted(std::vector<int> & vector)
{
	size_t size = vector.size();

	for(size_t i = 0; i < size - 1; i++)
	{
		//std::cout << vector[i] << " " << vector[i+1] << std::endl;
		if (vector[i] > vector [i + 1])
			return (false);
	}
	return (true);
}

/******************************************************************************
*                           DEQUE MEMBER FUNCTIONS                            *
******************************************************************************/

