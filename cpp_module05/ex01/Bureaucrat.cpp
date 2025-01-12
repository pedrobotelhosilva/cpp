#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
    os << "Bureaucrat " << other.getName();
    os << ", with grade ";
    os << other.getGrade();
    os << ".";
    return os;
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    if (this->getGrade() > 150)
        throw GradeTooLowException();
    else if (this->getGrade() < 1)
        throw GradeTooHighException();
    std::cout << this->_name << " constructor has been created.\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (this->getGrade() > 150)
        throw GradeTooLowException();
    else if (this->getGrade() < 1)
        throw GradeTooHighException();
    std::cout << this->_name << " constructor has been created.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;

    Bureaucrat tmp(other);
    std::swap(*this, tmp);
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The grade is too high. The highest grade should be 1.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The grade is too low. The lowest should be 150.\n");
}

void Bureaucrat::increment()
{
    if (this->_grade == 1)
        throw GradeTooHighException();
    --this->_grade;
}

void Bureaucrat::decrement()
{
    if (this->_grade == 150)
        throw GradeTooLowException();
    ++this->_grade;
}

void Bureaucrat::signForm(Form s)
{
    if (s.getSign() == true)
        std::cout << this->getName() << " signed " << s.getName() << "\n";
    else if (s.getSign() == false)
        std::cout << this->getName() << " couldn't sign " << s.getName() << " because the sign is " << s.getSign() << "\n";
}