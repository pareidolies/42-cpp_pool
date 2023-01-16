# include "Point.hpp"
# include <iostream>

int main(void)
{
    std::cout << "TEST 1" << std::endl;
	Point a1(0, 0);
	Point b1(1, 2);
	Point c1(2, 0);
	Point p1(1, 0);
    std::cout << "expected : false" << std::endl;
	std::cout << "computed : " << (bsp(a1, b1, c1, p1) ? "true" : "false") << std::endl;

    std::cout << "TEST 2" << std::endl;
	Point a2(1, 5);
	Point b2(12.2f, 2);
	Point c2(4.32f, 0);
	Point p2(1.5f, 1.5f);
    std::cout << "expected : false" << std::endl;
	std::cout << "computed : " << (bsp(a2, b2, c2, p2) ? "true" : "false") << std::endl;

    std::cout << "TEST 3" << std::endl;
	Point a3(0, 0);
	Point b3(2.2f, 2);
	Point c3(-4.32f, 10);
	Point p3(1.5f, 1.5f);
    std::cout << "expected : true" << std::endl;
	std::cout << "computed : " << (bsp(a3, b3, c3, p3) ? "true" : "false") << std::endl;

    std::cout << "TEST 4" << std::endl;
	Point a4(0, 0);
	Point b4(2.2f, 2);
	Point c4(-4.32f, 10);
	Point p4(2.2f, 2.0f);
    std::cout << "expected : false" << std::endl;
	std::cout << "computed : " << (bsp(a4, b4, c4, p4) ? "true" : "false") << std::endl;

	return 0;
}