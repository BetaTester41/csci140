#include <iostream>
#include <string>

void printStr(const char *);

int main(int argc, char const *argv[])
{
    char string[]{"to a string\0 of characters\n"};
    // equvelent to
    std::string str{string};

    std::cout << string;
    printStr(string);
    return 0;
}

void printStr(const char *str)
{
    while (*str)
        std::cout << *(str++);
}
