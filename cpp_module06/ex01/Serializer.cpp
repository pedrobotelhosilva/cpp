#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(Serializer const &ref)
{
    *this = ref;
}

Serializer& Serializer::operator=(Serializer const &ref)
{
    if (this != &ref) {}
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
