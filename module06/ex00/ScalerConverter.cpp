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

ScalarConverter::ScalarConverter(ScalarConverter const & copy) : _name(copy._name), _grade(copy._grade)
{

}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const & rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
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

void	ScalarConverter::convert(void)
{
	if (this->_grade - 1 < ScalarConverter::highestGrade)
		return (throw (ScalarConverter::GradeTooHighException()));
	else
	{
		this->_grade--;
		std::cout << "ScalarConverter " << this->_name << " got upgraded." << std::endl;
	}
}

/******************************************************************************
*                                  OPERATOR                                   *
******************************************************************************/

std::ostream &	operator<<(std::ostream & stream, ScalarConverter const & rhs)
{
	stream << ANSI_PURPLE << rhs.getName() << ", ScalarConverter grade " 
		<< rhs.getGrade() << "." << ANSI_RESET;
	return (stream);
}
