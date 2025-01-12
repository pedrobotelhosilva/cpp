#include "iter.hpp"

int main()
{
    int numbers[] = {10, 20, 30, 40, 50, 60};
    std::string phrases[] = {"Good ", "morning", "everyone", "have ", "a nice day"};

    std::size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);
    std::size_t phrasesLen = sizeof(phrases) / sizeof(phrases[0]);

    iter(numbers, numbersLen, [](const int& n) { std::cout << n << std::endl; });
    iter(phrases, phrasesLen, [](const std::string& phrase) { std::cout << phrase << std::endl; });

    return 0;
}
