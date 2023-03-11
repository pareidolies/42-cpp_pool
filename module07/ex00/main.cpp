# include "whatever.hpp"
# include <iostream>

int main()
{
	int nbr1 = 1;
	int nbr2 = 2;
	
	std::cout << "nbr1 = " << nbr1 << " | nbr2 = " << nbr2 << std::endl;
	::swap(nbr1, nbr2);
	std::cout << "nbr1 = " << nbr1 << " | nbr2 = " << nbr2 << std::endl;
	std::cout << "min(nbr1, nbr2) = " << ::min(nbr1, nbr2) << std::endl;
	std::cout << "max(nbr1, nbr2) = " << ::max(nbr1, nbr2) << std::endl;
	
	std::cout << std::endl;

	double dble1 = 1.2;
	double dble2 = 2.4;
	
	std::cout << "dble1 = " << dble1 << " | dble2 = " << dble2 << std::endl;
	::swap(dble1, dble2);
	std::cout << "dble1 = " << dble1 << " | dble2 = " << dble2 << std::endl;
	std::cout << "min(dble1, dble2) = " << ::min(dble1, dble2) << std::endl;
	std::cout << "max(dble1, dble2) = " << ::max(dble1, dble2) << std::endl;
	
	std::cout << std::endl;

	float flt1 = 42.42f;
	float flt2 = 42.42f;
	
	std::cout << "flt1 = " << flt1 << " | flt2 = " << flt2 << std::endl;
	::swap(flt1, flt2);
	std::cout << "flt1 = " << flt1 << " | flt2 = " << flt2 << std::endl;
	std::cout << "min(flt1, flt2) = " << ::min(flt1, flt2) << std::endl;
	std::cout << "max(flt1, flt2) = " << ::max(flt1, flt2) << std::endl;
	
	std::cout << std::endl;

	std::string str1 = "hello world";
	std::string str2 = "good bye world";

	std::cout << "str1 = " << str1 << " | str2 = " << str2 << std::endl;
	::swap(str1, str2);
	std::cout << "str1 = " << str1 << " | str2 = " << str2 << std::endl;
	std::cout << "min(str1, str2) = " << ::min(str1, str2) << std::endl;
	std::cout << "max(str1, str2) = " << ::max(str1, str2) << std::endl;
	
	return 0;
}
