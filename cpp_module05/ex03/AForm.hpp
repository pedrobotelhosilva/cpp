#pragma once
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _sign;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

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

    class FormNotSignedException : public std::exception
    {
        const char *what() const throw();
    };

    void beSigned(Bureaucrat bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;
};

#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const AForm& other);
