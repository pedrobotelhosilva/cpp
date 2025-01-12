#pragma once
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *_elements;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
        ~Array();
};

#include "Array.tpp"