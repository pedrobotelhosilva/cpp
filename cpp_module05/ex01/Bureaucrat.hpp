#pragma once
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    void increment();
    void decrement();

    std::string getName() const;
    int getGrade() const;

    void signForm(Form s);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);
