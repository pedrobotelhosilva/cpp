#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
    std::vector<int> container;
    unsigned int N;

public:
    Span();
    Span(unsigned int _N);
    void addNumber(const int& number);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    ~Span();
};
