#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private: 
        std::string _target;
    public:
        RobotomyRequestForm (std::string target);
        ~RobotomyRequestForm ();

    void execute(Bureaucrat const & executor) const;
};