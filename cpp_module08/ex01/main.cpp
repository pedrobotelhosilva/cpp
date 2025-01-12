#include "Span.hpp"

int main()
{
    try
    {
        Span numbers(6);
        numbers.addNumber(15);
        numbers.addNumber(34);
        numbers.addNumber(-12);
        numbers.addNumber(8);
        numbers.addNumber(56);
        numbers.addNumber(22);
        
        std::cout << "Longest span: " << numbers.longestSpan() << std::endl;
        std::cout << "Shortest span: " << numbers.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
