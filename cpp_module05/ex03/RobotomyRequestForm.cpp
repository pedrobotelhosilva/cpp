#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
     AForm("RobotomyRequestForm", 75, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    // Verifica se o formulário foi assinado antes de executar
    if (!this->getSign()) 
    {
        std::cout << "The form is not signed.\n";
        throw FormNotSignedException(); // Lança exceção se não estiver assinado
    }

    // Verifica se o grau do executor é suficiente para executar
    if (this->getToExecute() < executor.getGrade())
    {
        std::cout << "The robotomy failed.\n";
        throw GradeTooLowException(); // Lança exceção se o grau do executor for muito baixo
    }

    // Se o grau for adequado, realiza a ação
    std::cout << "Make drilling noise\n";
    std::cout << _target << " has been robotomized successfully 50% of the time.\n";
}
