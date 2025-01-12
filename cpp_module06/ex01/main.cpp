#include "Serializer.hpp"

int main() {
    Data* firstData = new Data;
    firstData->name = "Orion";
    firstData->height = 180;

    std::cout << "Original Address (firstData): " << firstData << std::endl;
    std::cout << "Name: " << firstData->name << std::endl;
    std::cout << "Height: " << firstData->height << std::endl;

    std::cout << "---------------------------------------------------------------------" << std::endl;

    Data* deserializedFirst = Serializer::deserialize(Serializer::serialize(firstData));
    std::cout << "After Deserialize Address (firstData): " << deserializedFirst << std::endl;
    std::cout << "Name: " << deserializedFirst->name << std::endl;
    std::cout << "Height: " << deserializedFirst->height << std::endl;

    std::cout << "=====================================================================" << std::endl;

    Data* secondData = new Data;
    secondData->name = "Nova";
    secondData->height = 165;

    std::cout << "Original Address (secondData): " << secondData << std::endl;
    std::cout << "Name: " << secondData->name << std::endl;
    std::cout << "Height: " << secondData->height << std::endl;

    std::cout << "---------------------------------------------------------------------" << std::endl;

    Data* deserializedSecond = Serializer::deserialize(Serializer::serialize(secondData));
    std::cout << "After Deserialize Address (secondData): " << deserializedSecond << std::endl;
    std::cout << "Name: " << deserializedSecond->name << std::endl;
    std::cout << "Height: " << deserializedSecond->height << std::endl;

    delete firstData;
    delete secondData;
    return 0;
}
