#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

struct Expression
{
    std::string expression;
    std::vector<std::string> infix_tokens;
    std::vector<std::string> postfix_tokens;

    void Tokenize();
    bool isNumber(const std::string&);
    void transform();
    bool PartialOrd(const std::string&, const std::string&);
};

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

bool Expression::PartialOrd(const std::string& a, const std::string& b) {
    const std::string ordered_operator_lists = "(+-*/^";
    return ordered_operator_lists.find(a) >= ordered_operator_lists.find(b);
}

int main(int argc, char *argv[])
{
    Expression expression{"2^5*(3-4)"};
    // std::cout << expression.infix_expression << std::endl;

    // Tokenize the expression
    expression.Tokenize();
    // for(auto i: expression.tokenized_expression) std::cout << i << " "; //show tokenized expression

    // Transform
    expression.transform();
    for(auto i: expression.postfix_tokens) std::cout << i; //show tokenized expression

    return 0;
}