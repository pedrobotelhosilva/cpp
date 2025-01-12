#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Invalid amount of arguments." << std::endl;
        return (1);
    }
    RPN calculate(argv[1]);
    return (0);
}