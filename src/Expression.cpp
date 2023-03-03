#include "Expression.h"
#include <stack>
#include <cmath>
#include <iostream> 

// Tokenize the infix_expression
void Expression::Tokenize()
{
    std::string token = "";
    for (auto &i : this->expression)
    {
        if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^' || i == ')' || i == '(')
        {
            token = i;
            this->infix_tokens.push_back(token);
            token = "";
        }
        else if (i == ' ')
        {
            continue;
        }
        else
        {
            token += i;
            if (&i == &this->expression.back() || isdigit(*(&i + 1)) == false)
            {
                this->infix_tokens.push_back(token);
                token = "";
            }
        }
    }
}

// Check if a string is a number
bool Expression::isNumber(const std::string &s) {
    for (auto &c : s)
    {
        if (isdigit(c) == false)
        {
            return false;
        }
    }
    return true;
}

// Convert a string to a number
float Expression::toNumber(const std::string &s) {
    long long t = 0;
    for (auto &c : s) {
        t *= 10;
        t += c - '0';
    }
    return (float)t;
}

// Transform the infix_expression to postfix expression
void Expression::transform()
{
    std::stack<std::string> stk;
    stk.push("(");
    this->infix_tokens.push_back(")");
    for (int i = 0; i < this->infix_tokens.size(); i++)
    {
        std::string token = this->infix_tokens[i];
        // std::cerr << "At token: " << token << std::endl;
        // std::cerr << "operator number: " << stk.size() << 
        //             " operand number: " << stk.size() << std::endl;

        if (token == "(")
        {
            stk.push("(");
        }
        else if (token == ")")
        {
            while(stk.top() != "(")
            {
                this->postfix_tokens.push_back(stk.top());
                stk.pop();
            } 
            stk.pop();
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^")
        {
            while(!stk.empty() && PartialOrd(stk.top(), token)) {
                this->postfix_tokens.push_back(
                    stk.top()
                );
                stk.pop();
            }
            // push stk only when stk.top is less than token
            stk.push(token);
        } else if(this->isNumber(token)) {
            stk.push(token);
        }
    }
}

// Compare two operators
bool Expression::PartialOrd(const std::string& a, const std::string& b) {
    const std::string ordered_operator_lists = "(+-*/^";
    return ordered_operator_lists.find(a) >= ordered_operator_lists.find(b);
}

// Evaluate the postfix_expression
float Expression::EvaluatePostfix() {
    std::stack<float> stk;
    for(auto token: this->postfix_tokens) {
        if(this->isNumber(token)) {
            stk.push(this->toNumber(token));
        } else {
            float b = stk.top(); stk.pop();
            float a = stk.top(); stk.pop();
            // std::cerr << a << " " << b << " " << token << std::endl;
            switch(token[0]) {
                case '+':
                    stk.push(a + b);
                    break;
                case '-':
                    stk.push(a - b);
                    break;
                case '*':
                    stk.push(a * b);
                    break;
                case '/':
                    if(abs(b) < float(1e-5)) {
                        throw std::runtime_error("divide by zero");
                    }
                    stk.push(a / b);
                    break;
                case '^':
                    stk.push(pow(a, b));
                    break;
                default:
                    break;
            }
        }
    }
    return stk.top();
}

float Expression::Evaluate() {
    this->Tokenize();
    this->transform();
    return this->EvaluatePostfix();
}