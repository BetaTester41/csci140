#include <iostream>

int main(int argc, char const *argv[])
{
    int a{10};
    int b{20};
    int c{50};

    // int c = (a > b) ? a : b; // (conditional) ? true : false;

    ((a > b) ? a : b) = c; // return a varable to be assigned to the value of c

    std::cout << a << " " << b << std::endl; // b now has the value of c
    
    return 0;
}
