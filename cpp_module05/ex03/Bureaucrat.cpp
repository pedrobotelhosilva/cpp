#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << "Bureaucrat " << other.getName() << ", with grade " << other.getGrade() << ".";
    return os;
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    if (_grade > 150)
        throw GradeTooLowException();
    if (_grade < 1)
        throw GradeTooHighException();
    std::cout << _name << " constructor has been created.\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (_grade > 150)
        throw GradeTooLowException();
    if (_grade < 1)
        throw GradeTooHighException();
    std::cout << _name << " constructor has been created.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "The grade is too high. The highest grade should be 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "The grade is too low. The lowest should be 150.";
}

void Bureaucrat::increment()
{
    if (_grade == 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrement()
{
    if (_grade == 150)
        throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(AForm& form)
{
    try {
        form.beSigned(*this);  // Chama beSigned para alterar o estado do formulário
        std::cout << _name << " signed " << form.getName() << "\n";
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << "\n";
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << "\n";
    }
}
