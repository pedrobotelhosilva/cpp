#include "Bureaucrat.hpp"

int main()
{
    std::cout << "********************\n";

    try {
        Bureaucrat michael("Michael", 75);
        std::cout << michael << " created successfully." << std::endl;
        michael.incrementGrade();
        std::cout << michael << " increment." << std::endl;
        michael.decrementGrade();
        std::cout << michael << " decrement." << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what();
    }

    std::cout << "********************\n";

    try {
        Bureaucrat sarah("Sarah", 1);
        std::cout << sarah << std::endl;
        sarah.incrementGrade();
        std::cout << sarah << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what();
    }

    std::cout << "********************\n";

    try {
        Bureaucrat john("John", 149);
        std::cout << john << " status: " << std::endl;
        john.decrementGrade();
        std::cout << john << " status: " << std::endl;
        john.decrementGrade();
        std::cout << john << " status: " << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what();
    }

    std::cout << "********************\n";

    try {
        Bureaucrat emily("Emily", -40);
        std::cout << emily << std::endl;
    } catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what();
        std::cout << "Grade was -40\n";
    } catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what();
    }

    return (0);
}
