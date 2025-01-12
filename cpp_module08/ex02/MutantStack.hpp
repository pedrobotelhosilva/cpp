#pragma once

#include <stack>
#include <deque>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        virtual ~MutantStack();
};

#include "MutantStack.tpp"
