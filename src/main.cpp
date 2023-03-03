#include <iostream>
#include <cmath>
#include "Expression.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <expression> <expression> ..." << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        Expression e{std::string(argv[i])};
        std::cout 
            << "(" << i << " of " << argc-1 << ") " 
            << "=> "
            << argv[i] << " = " << e.Evaluate()
            << std::endl;
    }
    return 0;
}