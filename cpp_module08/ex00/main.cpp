#include "easyfind.hpp"

int main()
{
    int num = 10;
    std::vector<int> container;
    container.push_back(3);
    container.push_back(12);
    container.push_back(7);
    container.push_back(10);

    std::vector<int>::iterator it;

    try
    {
        it = easyfind(container, num);
        std::cout << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
