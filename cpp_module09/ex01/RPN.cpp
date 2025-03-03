#include "RPN.hpp"
#include <iostream>

int RPN::checkOperator(char operation)
{
    if (operation != '+' && operation != '-' && operation != '/' && operation != '*')
    {
        std::cout << "Error: Invalid operation" << std::endl;
        exit(-1);
    }
    return (1);
}

void RPN::singleOperation()
{
    int operand1;
    int operand2;
    int result;
    char operation;

    operand2 = numbs.top();
    numbs.pop();
    operand1 = numbs.top();
    numbs.pop();
    operation = stack.top();
    stack.pop();

    switch (operation)
    {
        case '*':
            result = operand1 * operand2;
            break;
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '/':
            if (operand2 == 0)
            {
                std::cout << "Error: Division by zero" << std::endl;
                exit(-1);
            }
            result = operand1 / operand2;
            break;
        default:
            std::cout << "Error: Invalid operation" << std::endl;
            exit(-1);
    }
    numbs.push(result);
}

void RPN::fillStack()
{
    int expression_size = expression.size();

    if (expression_size < 3)
        exit(-1);

    for (int i = 0; i < expression_size; i++)
    {
        if (expression[i] != ' ')
        {
            if (isdigit(expression[i]))
                numbs.push(expression[i] - '0');
            else if (checkOperator(expression[i]))
                stack.push(expression[i]);

            if (stack.size() == 1 && numbs.size() >= 2)
                singleOperation();
        }
    }
}

std::string RPN::getExpression() const
{
    return (this->expression);
}

RPN::RPN(std::string input)
{
    expression = input;
    fillStack();
    if (!numbs.empty())
        std::cout << "Result: " << numbs.top() << std::endl;
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &src)
{
    this->expression = src.getExpression();
    return (*this);
}

RPN::~RPN() {}
