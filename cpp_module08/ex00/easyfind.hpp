#pragma once
#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int num)
{
    typename T::iterator it = container.begin();
    typename T::iterator end = container.end();

    while (it != end)
    {
        if (*it == num)
            return (it);
        ++it;
    }
    return (end);
}
