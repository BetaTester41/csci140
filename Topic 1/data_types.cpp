#include <iostream>

struct Student // struct default to public methods (class is private)
{
    std::string name; // 32
    unsigned int age; // 8 (4 + memalign)
};

int main (int argc, char const *argv[])
{
    int a{};
    // int array[5]; // 5 * 4 = 20 bytes
    // double array[5];
    double array[]{1,2,3,4,5}; // automatically determine size, and only size

    // when you pass array to function, you can no longer do sizeof(array)

    a = 10; // example of assignment operatior
    //a = array[0];  // doubles can convert to int (data may be lost)
    a += array[0]; // compound operator, adding to a

    //int c{a++, +b}; // since a++ adds after the value is captured, a doesn't increment in the value.
    // modulos return the remainder not the dividen
    // ++a is changed before expression is returned
    // additional info: https://en.cppreference.com/w/cpp/language/operator_precedence

    std::cout << sizeof(array) / sizeof(array[0]) << std::endl;

    return 0;
}