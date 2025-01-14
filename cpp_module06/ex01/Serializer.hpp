#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
    std::string name;
    int height;
};

class Serializer
{
    private:
        Serializer();
        Serializer& operator=(const Serializer& ref);
        Serializer(const Serializer& ref);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serializer();
};
