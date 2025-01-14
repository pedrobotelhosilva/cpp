#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input): _input(input)
{

}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    *this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & ref)
{
    if (this != &ref)
        this->_input = ref._input;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

std::string ScalarConverter::getInput() const
{
    return this->_input;
}

std::string ScalarConverter::to_string(double d)
{
    std::ostringstream s;
    s << d;
    return s.str();
}

bool ScalarConverter::checkNumber(std::string const s)
{
    if((s.find_first_of(".") != s.find_last_of(".") && (isdigit(s[s.find_first_of(".") + 1]) == false))||
        s.find_first_of(".") == 0 ||
        s.find_first_of(".") != s.find_last_of(".") ||
        (s.find_first_of("+-") != s.find_last_of("+-")) ||
        s.find_first_of("f") - s.find_first_of(".") == 1 ||
        s.find_first_of("f") != s.find_last_of("f"))
    {
        return true;
    }
    else if (s.find("f")  != std::string::npos)
    {
        if (s[s.find_first_of("f") + 1] != '\0')
            return true;
        return false;
    }
    else
        return false;
}

bool ScalarConverter::checkLetters(std::string const s)
{
    for (long unsigned int i = 0; i < s.length(); i++)
    {
        if (s.length() > 1)
        {
            if (isdigit(s[i]) == false)
            {
                if ((s[i] == '.' && s[i - 1] != 'f') || (s[i] == '.' && s[i + 2] == 'f') ||
                (s[i] == 'f' && s[i - 2] == '.') || (s[i] == '-' || s[i] == '+'))
                    return false;
                return true;
            }
        }
    }
    return false;
}

bool ScalarConverter::checkLiteral(std::string const s, int type)
{
    switch (type)
    {
        case CHAR:
        case INT:
            if ((s == "nan" || s == "-inf" || s == "+inf" || s =="nanf" || s == "-inff" || s == "+inff"))
                return true;
            return false;
        case FLOAT:
            if (s == "nanf" || s == "-inff" || s == "+inff")
                return true;
            return false;
        case DOUBLE:
            if (s.compare("nan") == 0 || s == "-inf" || s == "+inf")
                return true;
            return false;
    }
    return false;
}

void ScalarConverter::printOutput(void)
{
    this->printChar();
    this->printInt();
    this->printDouble();
    this->printFloat();
}

void ScalarConverter::printChar(void)
{
    int i;

    std::istringstream(this->_input) >> i;
    if (this->checkLiteral(this->_input, CHAR) || i < 0 || i > 128 )
        std::cout << "char: impossible" << std::endl;
    else if (i < 32 || i > 127 || checkLetters(this->_input))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << (char) i << "'" << std::endl;
}

void ScalarConverter::printInt()
{
    double d;

    std::istringstream(this->_input) >> d;
    if (this->checkLiteral(this->_input, INT) || (d == 0 && this->_input != "0") ||
        d < INT_MIN || d > INT_MAX || this->checkNumber(this->_input) || this->checkLetters(this->_input))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << (int) d << std::endl;
}

void ScalarConverter::printDouble(void)
{
    long double dd;

    std::istringstream(this->_input) >> dd;
    if (this->checkLiteral(this->_input, DOUBLE))
        std::cout << "double: " << this->getInput() <<std::endl;
    else if ((dd != 0 && (dd < std::numeric_limits<int>::min() || dd > std::numeric_limits<int>::max())) || this->checkNumber(this->_input) || this->checkLetters(this->_input))
        std::cout << "double: impossible" << std::endl;
    else if (to_string((double) dd).find(".") != std::string::npos)
        std::cout << "double: " <<(double) dd << std::endl;
    else
        std::cout << "double: " << (double) dd << ".0" <<std::endl;
}

void ScalarConverter::printFloat(void)
{
    double d;

    std::istringstream(this->_input) >> d;
    if (this->checkLiteral(this->_input, DOUBLE))
        this->_input += "f";
    if (this->checkLiteral(this->_input, FLOAT))
        std::cout << "float: " << this->getInput() << std::endl;
    else if ((d != 0 &&  (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())) || this->checkNumber(this->_input) || this->checkLetters(this->_input))
        std::cout << "float: impossible" << std::endl;
    else if (to_string(d).find(".") != std::string::npos)
        std::cout << "float: " << (float) d << "f" << std::endl;
    else
        std::cout << "float: " << (float) d << ".0f" << std::endl;
}
