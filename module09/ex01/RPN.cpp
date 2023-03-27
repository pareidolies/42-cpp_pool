# include "RPN.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

RPN::RPN(void)
{

}

RPN::RPN(const std::string &input) :_input(input)
{
	
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

RPN::RPN(RPN const & copy) : _input(copy._input), _stack(copy._stack)
{

}

RPN	&RPN::operator=(RPN const & rhs)
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

RPN::~RPN(void)
{

}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

bool			RPN::isOperator(char c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool			RPN::isDigit(char c) 
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

double			RPN::compute(void)
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
				throw (RPN::WrongOrderException());

            nbr2 = _stack.top();

			if (nbr2 == 0 && c == '/')
				throw (RPN::DivisionByZeroException()); // add check for stack size
			
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
			throw (RPN::WrongCharException());
    }
    
	if (_stack.size() != 1) 
		throw (RPN::WrongOrderException());

    return (_stack.top());
}

/******************************************************************************
*                                EXCEPTIONS                                   *
******************************************************************************/

const char *RPN::WrongOrderException::what() const throw() 
{
	return ("Error: The order does not follow the Reverse Polish Notation rules");
}
		
const char *RPN::WrongCharException::what() const throw() 
{
	return ("Error: Wrong character detected");
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return ("Error: Division by zero is forbidden");
}
