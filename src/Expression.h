#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <vector>

struct Expression
{    
    std::string expression;
    std::vector<std::string> infix_tokens;
    std::vector<std::string> postfix_tokens;

    void Tokenize();
    bool isNumber(const std::string&);
    void transform();
    bool PartialOrd(const std::string&, const std::string&);
    float Evaluate();
    float EvaluatePostfix();
    float toNumber(const std::string&);
};

#endif