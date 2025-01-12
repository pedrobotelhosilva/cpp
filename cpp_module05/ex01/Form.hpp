#pragma once
#include <iostream>
#include <stdbool.h>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _sign;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);

    void beSigned(Bureaucrat &bureaucrat);

    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getToExecute() const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    ~Form();
};

#include "Bureaucrat.hpp"
std::ostream &operator<<(std::ostream &os, const Form &other);