#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try {
        Bureaucrat A("bureaucrat", 5);
        std::cout << A << std::endl;

        ShrubberyCreationForm C("home");
        C.execute(A);

        std::cout << "******************************\n";
        
        PresidentialPardonForm P("target");
        P.execute(A);

        std::cout << "******************************\n";
        
        RobotomyRequestForm R("robot");
        R.execute(A);

    } catch(const std::exception& e) {
        std::cerr << e.what();
    }

    return (0);
}
