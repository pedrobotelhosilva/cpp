#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> defaultArray;
        std::cout << "Test 1: Default Constructor" << std::endl;
        std::cout << "defaultArray size: " << defaultArray.size() << std::endl;
        std::cout << "-----------------------" << std::endl;

        Array<int> intNumbers(5);
        std::cout << "Test 2: Parameterized Constructor" << std::endl;
        std::cout << "intNumbers size: " << intNumbers.size() << std::endl;
        std::cout << "intNumbers elements (default initialization): ";
        for (unsigned int i = 0; i < intNumbers.size(); i++) {
            std::cout << intNumbers[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "-----------------------" << std::endl;

        for (unsigned int i = 0; i < intNumbers.size(); i++) {
            intNumbers[i] = i * 2;
        }
        std::cout << "Test 3: Modify Elements" << std::endl;
        std::cout << "intNumbers elements after modification: ";
        for (unsigned int i = 0; i < intNumbers.size(); i++) {
            std::cout << intNumbers[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "-----------------------" << std::endl;

        Array<int> copiedNumbers = intNumbers;
        copiedNumbers[0] = 100;
        std::cout << "Test 4: Copy Constructor" << std::endl;
        std::cout << "Original intNumbers[0]: " << intNumbers[0] << std::endl;
        std::cout << "Copied copiedNumbers[0]: " << copiedNumbers[0] << std::endl;
        std::cout << "-----------------------" << std::endl;

        Array<int> assignedNumbers;
        assignedNumbers = intNumbers;
        assignedNumbers[1] = 200;
        std::cout << "Test 5: Assignment Operator" << std::endl;
        std::cout << "Original intNumbers[1]: " << intNumbers[1] << std::endl;
        std::cout << "Assigned assignedNumbers[1]: " << assignedNumbers[1] << std::endl;
        std::cout << "-----------------------" << std::endl;

        std::cout << "Test 6: Access Out of Bounds" << std::endl;
        try {
            std::cout << intNumbers[10] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "-----------------------" << std::endl;

        const Array<int> constNumbers(3);
        std::cout << "Test 7: Const Array" << std::endl;
        std::cout << "constNumbers size: " << constNumbers.size() << std::endl;
        try {
            std::cout << "constNumbers[1]: " << constNumbers[1] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "-----------------------" << std::endl;

        Array<std::string> messageArray(3);
        messageArray[0] = "Welcome";
        messageArray[1] = "to";
        messageArray[2] = "C++";
        std::cout << "Test 8: Non-Primitive Types" << std::endl;
        for (unsigned int i = 0; i < messageArray.size(); i++) {
            std::cout << "messageArray[" << i << "]: " << messageArray[i] << std::endl;
        }
        std::cout << "-----------------------" << std::endl;

        Array<int> largeArray(10);
        std::cout << "Test 9: Larger Array and Modifications" << std::endl;
        for (unsigned int i = 0; i < largeArray.size(); i++) {
            largeArray[i] = i * 3;
        }
        std::cout << "largeArray elements: ";
        for (unsigned int i = 0; i < largeArray.size(); i++) {
            std::cout << largeArray[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "-----------------------" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}