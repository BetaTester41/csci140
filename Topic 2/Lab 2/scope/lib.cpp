#include <iostream>

int k{25};

void printK()
{
    int k{100};
    std::cout << k << std::endl;

    {
        int k{55};
        std::cout << k << std::endl;
    }

    std::cout << k << std::endl;
}