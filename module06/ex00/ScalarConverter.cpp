# include "ScalarConverter.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

ScalarConverter::ScalarConverter(void)
{

}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

ScalarConverter::ScalarConverter(ScalarConverter const & copy)
{
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const & rhs)
{
	this->_value = rhs._value;
	this->convert(this->_value);
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

ScalarConverter::~ScalarConverter(void)
{

}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

void	ScalarConverter::convert(std::string value)
{
	this->_value = value;
	this->_isNan = false;
	this->_isExtreme = false;
	this->_isChar = false;
	this->_isOverflow = false;
	this->_float = 0;
	this->_int = 0;
	this->_char = 0;
	this->_double = 0;
	if (checkValue())
		convertValue();
}

bool	ScalarConverter::checkValue(void)
{
	unsigned long	i;
	std::string		tmp(_value);

	if (tmp.compare("inf") == 0 || tmp.compare("inff") == 0 
		|| tmp.compare("-inf") == 0 || tmp.compare("-inff") == 0
		|| tmp.compare("+inf") == 0 || tmp.compare("+inff") == 0)
	{
		_isExtreme = true;
		return (false);
	}
	if (tmp.compare("nan") == 0 || tmp.compare("nanf") == 0)
	{
		_isNan = true;
		return (false);
	}
	if (tmp.size() == 3 && tmp[0] == '\'' && tmp[2] == '\'')
	{
		_isChar = true;
		return (true);
	}
	if (tmp[tmp.size() - 1] == 'f')
		tmp.resize(tmp.size() - 1);
	i = 0;
	if (tmp[i] == '-')
		i++;
	while (i < tmp.size() && isdigit(tmp[i]))
		i++;
	if (i != tmp.size() && tmp[i] != '.')
	{
		_isNan = true;
		return (false);
	}
	if (tmp[i] == '.' && tmp[i + 1])
		i++;
	while (i < tmp.size() && isdigit(tmp[i]))
		i++;
	if (i != tmp.size())
	{
		_isNan = true;
		return (false);
	}
	return (true);
}

void	ScalarConverter::convertValue(void)
{
	if (_isChar)
	{
		_char = _value[1];
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else
	{
		_double = atof(_value.c_str());
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
		if (_double < INT_MIN || _double > INT_MAX)
			_isOverflow = true;

	}
}

void	ScalarConverter::printAll(std::ostream &stream) const
{
	if (_isExtreme)
	{
		if (_value.compare("inf") == 0 || _value.compare("inff") == 0 
		|| _value.compare("+inf") == 0 || _value.compare("+inff") == 0)
		{
			stream << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: +inf" << std::endl
				<< "double: +inff" << std::endl; 
		}
		if (_value.compare("-inf") == 0 || _value.compare("-inff") == 0)
		{
			stream << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: -inf" << std::endl
				<< "double: -inff" << std::endl; 
		}
	}
	else if (_isNan)
	{
		stream	<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: nanf" << std::endl
				<< "double: nan" << std::endl;
	}
	else
	{
		if (isprint(_int))
			stream << "char: \'" << _char << "\'" << std::endl;
		else
			stream << "char: Non displayable" << std::endl;
		if (_isOverflow)
			stream << "int: impossible" << std::endl;
		else
			stream << "int: " << _int << std::endl;
		if ((_float - roundf(_float) == 0) && !isinf(_float) && (_float < 1000000) && (_float > -1000000))
			stream << "float: " << _float << ".0f" << std::endl;
		else
			stream << "float: " << _float << "f" << std::endl;
		if ((_double - roundf(_double) == 0) && !isinf(_double) && (_double < 1000000) && (_double > -1000000))
			stream << "double: " << _double << ".0" << std::endl;
		else
			stream << "double: " << _double << std::endl;
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, ScalarConverter const & rhs)
{
	rhs.printAll(stream);
	return (stream);
}
