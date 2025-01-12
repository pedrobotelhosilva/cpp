#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat john("John", 10);
        std::cout << john << std::endl;

        Form formA("Form A", 10, 10);
        std::cout << formA << std::endl;

        formA.beSigned(john);
        std::cout << formA;
        john.signForm(formA);
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }

    std::cout << "******************************\n";

    try {
        Bureaucrat emily("Emily", 50);
        std::cout << emily << std::endl;

        Form formB("Form B", 10, 10);
        std::cout << formB << std::endl;

        formB.beSigned(emily);
        emily.signForm(formB);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "******************************\n";

    try {
        Bureaucrat invalidBureaucrat("Invalid", 200);
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }

    std::cout << "******************************\n";

    try {
        Bureaucrat mike("Mike", 2);
        std::cout << mike << std::endl;

        mike.decrement();
        std::cout << mike << std::endl;

        mike.decrement();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
