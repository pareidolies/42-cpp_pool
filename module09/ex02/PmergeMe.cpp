# include "PmergeMe.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe()
{
	
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PmergeMe::PmergeMe(PmergeMe const & copy) : _vector(copy._vector), _list(copy._list)
{

}

PmergeMe	&PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_list = rhs._list;
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
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool			PmergeMe::isOperator(char c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool			PmergeMe::isDigit(char c) 
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

double			PmergeMe::compute(void)
{
	int		nbr1, nbr2;
	double	res;
	char	c; 

    for (std::string::const_iterator it = _input.begin(); it != _input.end(); ++it) 
	{
		c = *it;

        if (isDigit(c)) 
            _stack.push(c - '0');
		else if (isOperator(c)) 
		{
			if (_stack.size() < 2)
				throw (PmergeMe::WrongOrderException());

            nbr2 = _stack.top();

			if (nbr2 == 0 && c == '/')
				throw (PmergeMe::DivisionByZeroException()); // add check for stack size
			
			_stack.pop();
            nbr1 = _stack.top();
			_stack.pop();
            
            switch(c) 
			{
                case '+' : res = nbr1 + nbr2; break;
                case '-' : res = nbr1 - nbr2; break;
                case '*' : res = nbr1 * nbr2; break;
                case '/' : res = nbr1 / nbr2; break;
            }
            _stack.push(res);
        } 
		else if (c != ' ') 
			throw (PmergeMe::WrongCharException());
    }
    
	if (_stack.size() != 1) 
		throw (PmergeMe::WrongOrderException());

    return (_stack.top());
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
