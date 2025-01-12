#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "******************************\n";

    {
        Bureaucrat A("bureaucrat", 5);
        Intern RandomIntern;
        AForm* form = RandomIntern.makeForm("ShrubberyCreationForm", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            A.signForm(*form);
            try
            {
                form->execute(A);  // Tenta executar o formulário
            }
            catch (const AForm::GradeTooLowException& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;  // Exibe a mensagem de erro se o grau for muito baixo
            }
            delete form;
        }
    }

    std::cout << "******************************\n";

    {
        Bureaucrat B("robot", 45);
        Intern RandomIntern;
        AForm* form = RandomIntern.makeForm("RobotomyRequestForm", "R2D2");
        if (form)
        {
            std::cout << *form << std::endl;
            B.signForm(*form);
            try
            {
                form->execute(B);  // Tenta executar o formulário
            }
            catch (const AForm::GradeTooLowException& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;  // Exibe a mensagem de erro se o grau for muito baixo
            }
            delete form;
        }
    }

    std::cout << "******************************\n";

    {
        Bureaucrat C("president", 10);
        Intern RandomIntern;
        AForm* form = RandomIntern.makeForm("PresidentialPardonForm", "Darth Vader");
        if (form)
        {
            std::cout << *form << std::endl;
            C.signForm(*form);
            try
            {
                form->execute(C);  // Tenta executar o formulário
            }
            catch (const AForm::GradeTooLowException& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;  // Exibe a mensagem de erro se o grau for muito baixo
            }
            delete form;
        }
    }

    return 0;
}

