# include "PmergeMe.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const std::string &arg) : _arg(arg)
{
	
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PmergeMe::PmergeMe(PmergeMe const & copy) : _arg(copy._arg)
{

}

PmergeMe	&PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		_arg = rhs._arg;
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

void	PmergeMe::checkArg()
{

}

void	PmergeMe::fillVector()
{

}

void	PmergeMe::checkDuplicates()
{

}

void	PmergeMe::sortVector()
{

}


void	PmergeMe::createPairsVector()
{

}


void	PmergeMe::sortPairsVector()
{

}


void	PmergeMe::mergeVector()
{

}

void	PmergeMe::binarySearchVector()
{

}

void	PmergeMe::insertAtPositionVector()
{

}

void	PmergeMe::printVector(std::vector<int> & vector)
{
	size_t size = vector.size();

	std::cout << ANSI_PURPLE << "Before: ";
	for(size_t i = 0; i < size; i++)
		std::cout << vector[i] << " ";
	std::cout << ANSI_RESET << std::endl;

}

/******************************************************************************
*                                  PRINTERS                                   *
******************************************************************************/

void PmergeMe::printSortedVector()
{
	size_t size = _vector.size();

	std::cout << ANSI_YELLOW << "After: ";
	for(size_t i = 0; i < size; i++)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << ANSI_RESET << std::endl;
}

void PmergeMe::printUnsortedVector(std::vector<int>	& vector)
{
	size_t size = vector.size();

	std::cout << ANSI_PURPLE << "Before: ";
	for(size_t i = 0; i < size; i++)
		std::cout << vector[i] << " ";
	std::cout << ANSI_RESET << std::endl;
}

void PmergeMe::printSortedList()
{
	std::cout << ANSI_YELLOW << "After: ";
	for(std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << ANSI_RESET << std::endl;
}

void PmergeMe::printUnsortedList(std::list<int>	& list)
{
	std::cout << ANSI_YELLOW << "Before: ";
	for(std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << ANSI_RESET << std::endl;
}
