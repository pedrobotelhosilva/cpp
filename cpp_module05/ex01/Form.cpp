#include "Form.hpp"
#include <iostream>

Form::Form() : _name("default"), _sign(false), _gradeToSign(15), _gradeToExecute(15)
{
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw GradeTooLowException();
    else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw GradeTooHighException();
    std::cout << this->_name << " has been created.\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
    _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw GradeTooLowException();
    else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw GradeTooHighException();
    std::cout << this->_name << " has been created.\n";
}

Form::Form(const Form &other) : _name(other._name), _sign(other._sign), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_sign = other._sign;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSign() const
{
    return this->_sign;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getToExecute() const
{
    return this->_gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("The grade is too high.\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("The grade is too low.\n");
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeToSign())
        this->_sign = true;
    else
    {
        std::cout << "The form cannot be signed. ";
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
    os << std::boolalpha;
    os << "Form name ";
    os << other.getName() << " with sign ";
    os << other.getSign() << " and Grade to Sign: ";
    os << other.getGradeToSign() << " and grade to Execute: ";
    os << other.getToExecute() << std::endl;
    return os;
}
