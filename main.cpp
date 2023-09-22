#include <iostream>
#include "./predictive_parser.h"

int main()
{
    std::cout << parse("a*a+a") << std::endl;
    std::cout << parse("a*a") << std::endl;
    std::cout << parse("a") << std::endl;
    std::cout << parse("a*a+a+b") << std::endl;
    std::cout << parse("a+b") << std::endl;
    std::cout << parse("a*a*a*a*a*a") << std::endl;

    return 0;
}