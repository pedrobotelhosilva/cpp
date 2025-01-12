#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T* array, std::size_t length, F func)
{
    if (length <= 0)
    {
        std::cerr << "The number should be positive" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}
