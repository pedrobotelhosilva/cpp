#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getToExecute() >= executor.getGrade())
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
    else
    {
        std::cout << "The Bureaucrat grade is too high and the Form grade is too low to execute.\n";
        throw GradeTooLowException();
    }
}