#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _sign(false), _gradeToSign(15), _gradeToExecute(15) 
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    std::cout << _name << " has been created.\n";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
    _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    std::cout << _name << " has been created.\n";
}

AForm::AForm(const AForm& other)
    : _name(other._name), _sign(other._sign), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _sign = other._sign;
        // _name, _gradeToSign, and _gradeToExecute are const and cannot be reassigned.
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getSign() const { return _sign; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getToExecute() const { return _gradeToExecute; }

const char* AForm::GradeTooHighException::what() const throw() {
    return "The grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "The grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed.";
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _sign = true;
    else
    {
        std::cout << "The form cannot be signed: ";
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
    os << std::boolalpha;
    os << "AForm name: " << other.getName() << ", signed: " << other.getSign() 
       << ", Grade to Sign: " << other.getGradeToSign() 
       << ", Grade to Execute: " << other.getToExecute() << "\n";
    return os;
}
