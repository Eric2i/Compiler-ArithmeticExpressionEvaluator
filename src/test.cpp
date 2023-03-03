#include <iostream>
#include <functional>
#include <cmath>
#include "Expression.h"

const float eps = 1e-5;

int test_01()
{
    // trival infix expression test
    Expression exp = {"1-2+3-4+5-6"};
    float true_result = -3;

    float evaluation = exp.Evaluate();
    assert(abs(evaluation - true_result) < eps);

    return 0;
}

int test_02()
{
    // infix expression test with parenthesis
    Expression exp = {"(1+2)*(3+4)*5+6"};
    float true_result = 111;
    float evaluation = exp.Evaluate();
    assert(abs(evaluation - true_result) < eps);

    return 0;
}

int test_03()
{
    // infix expression with redundant parenthesis
    Expression exp = {"(((1+2)*(3+4)))*5+6"};
    float true_result = 111;

    float evaluation = exp.Evaluate();
    assert(abs(evaluation - true_result) < eps);

    return 0;
}

int test_04()
{
    // infix expression with divided by zero
    Expression exp = {"24/0"};
    float true_result = INFINITY;
    float evaluation = exp.Evaluate();
    assert(true_result == evaluation);
    return 0;
}

std::vector<std::function<int()>> testing_lists = {
    test_01,
    test_02,
    test_03,
    test_04,
};

int main(int argc, char *argv[])
{
    for (size_t i = 0; i < testing_lists.size(); i++)
    {
        std::cerr << "Testing " << i + 1 << " of " << testing_lists.size() << ":\n";
        testing_lists[i]() == 0 ? std::cout << "[PASS]\n" : std::cout << "[FAIL]\n";
    }

    return 0;
}