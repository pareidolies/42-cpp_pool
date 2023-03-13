# include "Span.hpp"

# include <iostream>
# include <vector>

int main()
{
    std::cout << ANSI_BLUE << "-Minispan-" << ANSI_RESET << std::endl;

    Span minispan = Span(4);

    minispan.addNumber(-12);
    minispan.addNumber(0);
    minispan.addNumber(2);
    minispan.addNumber(27);

    minispan.printSpan();
    std::cout << "Size: " << minispan.getSize() << std::endl;
    std::cout << "Shortest span: " << minispan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << minispan.longestSpan() << std::endl;

    try
    {    
        minispan.addNumber(4);
    }
    catch (std::exception const & e)
    {
        std::cout << ANSI_RED << e.what() << ANSI_RESET << std::endl;
    }

    std::cout << std::endl;

    std::cout << ANSI_BLUE << "-Hugespan-" << ANSI_RESET << std::endl;

    Span hugespan = Span(10000);

    hugespan.addNumber(150);
    hugespan.addNumber(-7);
    hugespan.addNumber(1);
    hugespan.addNumber(6);
    hugespan.addNumber(26);

    hugespan.fillSpan(minispan.getVector().begin(), minispan.getVector().end());
    
    hugespan.printSpan();
    std::cout << "Size: " << hugespan.getSize() << std::endl;
    std::cout << "Shortest span: " << hugespan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << hugespan.longestSpan() << std::endl;

    std::cout << ANSI_GREEN << "New fill for hugespan!" << ANSI_RESET << std::endl;

    try
    {
        for(int i = 0; i < 10000; i++)
            hugespan.fillSpan(hugespan.getVector().begin(), hugespan.getVector().end());
    }
    catch (std::exception const & e)
    {
        std::cout << ANSI_RED << e.what() << ANSI_RESET << std::endl;
    }
    hugespan.printSpan();
    std::cout << "Size: " << hugespan.getSize() << std::endl;
    std::cout << "Shortest span: " << hugespan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << hugespan.longestSpan() << std::endl;
}
