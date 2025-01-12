#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }

    try
    {
        BitcoinExchange bitcoin;
        bitcoin.handleInputFile(argv[1]);
    }
    catch (const std::string &error)
    {
        std::cout << "Error: " << error << std::endl;
    }

    return (0);
}
