# include "Serializer.hpp"

/******************************************************************************
*                              CONSTRUCTORS                                   *
******************************************************************************/

Serializer::Serializer(void)
{

}

/******************************************************************************
*                                   COPY                                      *
******************************************************************************/

Serializer::Serializer(Serializer const & copy)
{
	*this = copy;
}

Serializer	&Serializer::operator=(Serializer const & rhs)
{
	(void) rhs;
	return (*this);
}

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Serializer::~Serializer(void)
{

}

/******************************************************************************
*                             MEMBER FUNCTIONS                                *
******************************************************************************/

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t result;
	
	result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* result;
	
	result = reinterpret_cast<Data*>(raw);
	return (result);
}
