#include "Base.hpp"

int main()
{
    srand(time(NULL));

    Base *objects[5];
    for (int i = 0; i < 5; i++)
    {
        objects[i] = generate();
        if (objects[i] == NULL)
            return 1;

        std::cout << "Test " << i << " - Pointer: ";
        identify(objects[i]);

        std::cout << "Test " << i << " - Reference: ";
        identify(*objects[i]);

        delete objects[i];
        std::cout << std::endl;
    }

    Base *extraTest = generate();
    if (extraTest == NULL)
        return 1;

    std::cout << "Extra Test - Pointer: ";
    identify(extraTest);

    std::cout << "Extra Test - Reference: ";
    identify(*extraTest);

    delete extraTest;

    return 0;
}
