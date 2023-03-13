# include "Span.hpp"

# include <iostream>

int main()
{
    std::cout << ANSI_BLUE << "-Minispan-" << ANSI_RESET << std::endl;

    Span minispan = Span(4);

    minispan.addNumber(-12);
    minispan.addNumber(0);
    minispan.addNumber(2);
    minispan.addNumber(27);

    minispan.printSpan();

    try
    {
        std::cout << "Shortest span: " << minispan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << minispan.longestSpan() << std::endl;
        minispan.addNumber(4);
    }
    catch (std::exception const & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << ANSI_BLUE << "-Hugespan-" << ANSI_RESET << std::endl;

    Span hugespan = Span(20);

    hugespan.addNumber(15);
    hugespan.addNumber(-7);
    hugespan.addNumber(1);
    hugespan.addNumber(6);

    hugespan.printSpan();
    std::cout << "Shortest span: " << hugespan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << hugespan.longestSpan() << std::endl;

    std::cout << ANSI_GREEN << "New fill for hugespan!" << ANSI_RESET << std::endl;

    try
    {
        //std::cout << *(minispan.getVector().end() - 1) << std::endl;
        //minispan.printSpan();
        hugespan.fillSpan(minispan.getVector().begin(), minispan.getVector().end());
        hugespan.printSpan();
        std::cout << "Shortest span: " << minispan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << minispan.longestSpan() << std::endl;

    }
    catch (std::exception const & e)
    {
        std::cout << e.what() << std::endl;
    }

}
