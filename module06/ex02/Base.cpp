# include "Base.hpp"

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

/******************************************************************************
*                                DESTRUCTOR                                   *
******************************************************************************/

Base::~Base(void)
{

}

/******************************************************************************
*                                 FUNCTIONS                                   *
******************************************************************************/

Base *	generate(void)
{
	int result;
	
	result = rand() % 3;
	switch(result)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer is of base A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer is of base B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer is of base C" << std::endl;
	else
		std::cout << "Pointer is neither of base A, B nor C" << std::endl;
}

void	identify(Base& p)
{
	int	base = 0;
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Reference is of base A" << std::endl;
		base = 1;
	}
	catch (const std::exception & e)
	{}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "Reference is of base B" << std::endl;
		base = 1;
	}
	catch (const std::exception & e)
	{}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "Reference is of base C" << std::endl;
		base = 1;
	}
	catch (const std::exception & e)
	{}
	if (!base)
		std::cout << "Reference is neither of base A, B nor C" << std::endl;
}
