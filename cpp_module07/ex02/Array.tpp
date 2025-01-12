#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
    _elements = new T[size];
}

template <typename T>
Array<T>::Array(const Array &other) : _elements(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        _elements[i] = other._elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        T *temp = new T[other._size]; // Allocate temporary memory
        for (unsigned int i = 0; i < other._size; i++)
        {
            temp[i] = other._elements[i];
        }
        delete[] _elements;
        _elements = temp;
        _size = other._size;
    }
    return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("index out of bounds");
    }
    return (_elements[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("index out of bounds");
    }
    return (_elements[index]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _elements;
}
