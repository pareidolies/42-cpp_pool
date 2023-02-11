# include "ScalarConverter.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

ScalarConverter::ScalarConverter(void) : _isNan(false), _isExtreme(false), _isChar(false)
{
	this->_float = 0;
	this->_int = 0;
	this->_char = 0;
	this->_double = 0;
}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

ScalarConverter::ScalarConverter(ScalarConverter const & copy)
{

}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const & rhs)
{
	if (this != &rhs)
		this->_isNan = rhs._isNan;
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
	if (checkValue(value))
		convertValue(value);
}

void	ScalarConverter::checkValue(std::string value)
{
	unsigned long	i;
	std::string		tmp(value);

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

void	ScalarConverter::convertValue(std::string value)
{
	if (_isChar)
	{
		_char = value[1];
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else
	{
		_double = atof(value.c_str());
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, ScalarConverter const & rhs)
{
	if (_isExtreme)
	{
		if (_value.compare("inf") == 0 || _value.compare("inff") == 0 
		|| _value.compare("+inf") == 0 || _value.compare("+inff") == 0)
		{
			stream << ANSI_BLUE 
				<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: +inf" << std::endl
				<< "double: +inff" << std::endl; 
				<< ANSI_RESET;
		}
		if (_value.compare("-inf") == 0 || _value.compare("-inff") == 0)
		{
			stream << ANSI_BLUE 
				<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: -inf" << std::endl
				<< "double: -inff" << std::endl; 
				<< ANSI_RESET;
		}
	}
	else if (_isNan)
	{
		stream	<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: nanf" << std::endl
				<< "double: nan" << std::endl;
	}
	else if (_isChar)
	{
		if (_value[1] >= 32 && _value[1] <= 127)
			stream << "char: \"" << _value[1] << "\"" << std::endl;
		else
			stream << "char: Non displayable" << std::endl;
	}
	else
	{

	}
	return (stream);
}
