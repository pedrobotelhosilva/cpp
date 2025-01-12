#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
     AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getToExecute() >= executor.getGrade())
    {
        std::string nameFile = _target + "_shrubbery";
        std::ofstream MyFile(nameFile.c_str());
        MyFile << "       #\n"
               << "      ###\n"
               << "     #####\n"
               << "    #######\n"
               << "   #########\n"
               << "  ###########\n"
               << " #############\n"
               << "###############\n"
               << "       H\n"
               << "       H\n"
               << "       H\n";
        MyFile.close();
        std::cout << "The file has been created.\n";
    }
    else
    {
        std::cout << "The file was not created. The Bureaucrat grade is: " << executor.getGrade() << "\n";
        throw GradeTooLowException();
    }
}
