#include <iostream>

void swap(int, int);

int main(int argc, char const *argv[])
{
    int i{10};
    int j{20};

    int& k{j};

    std::cout << i << " " << j << std::endl;

    swap(i, j);

    std::cout << i << " " << j << std::endl;

    return 0;
}

void swap(int a, int b)
{
    int temp{a};
    a = b;
    b = temp;

    // less clock cycle
    // a ^= b;
    // b ^= a;
    // a ^= b;
    std::cout << a << " " << b << std::endl;
}
