# include "PmergeMe.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const std::string &input) :_input(input)
{
	
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

PmergeMe::PmergeMe(PmergeMe const & copy) : _input(copy._input), _stack(copy._stack)
{

}

PmergeMe	&PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		_input = rhs._input;
		_stack = rhs._stack;
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
*                                EXCEPTIONS                                   *
******************************************************************************/

const char *PmergeMe::WrongOrderException::what() const throw() 
{
	return ("Error: The order does not follow the Reverse Polish Notation rules");
}
		
const char *PmergeMe::WrongCharException::what() const throw() 
{
	return ("Error: Wrong character detected");
}

const char *PmergeMe::DivisionByZeroException::what() const throw()
{
	return ("Error: Division by zero is forbidden");
}
