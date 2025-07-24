#include <iostream>

int f;
void staticExample();

int main(int argc, char const *argv[])
{
    staticExample();
    staticExample();
    staticExample();

    return 0;
}

void staticExample()
{
    static int a{55};
    int b{10};

    std::cout << a << std::endl;

    ++a;
}