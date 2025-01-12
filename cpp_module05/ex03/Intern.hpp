#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
    
    public:
        Intern();
        ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target);
};