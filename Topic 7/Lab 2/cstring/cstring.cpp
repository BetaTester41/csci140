#include <iostream>

namespace commonLib
{
    void toUpper(char *);
    void toLower(char *);
}
void printStr(const char *);
size_t strlen(const char *);

int main(int argc, char const *argv[])
{
    char string[]{"to a string\0 of characters\n"};
    char altstr[]("123456789");
    char bigstr[100]("AbCdEf");
    // equvelent to
    std::string str{string};

    std::cout << string; // prints the entire string
    printStr(string);    // prints every char

    std::cout << strlen(altstr) << std::endl;
    commonLib::toUpper(bigstr);
    std::cout << bigstr << std::endl;
    commonLib::toLower(bigstr);
    std::cout << bigstr << std::endl;

    return 0;
}

void printStr(const char *str)
{
    while (*str)
        std::cout << *(str++);
    std::cout << std::endl;
}

size_t strlen(const char *str)
{
    const char *it{str};
    while (*(it++))
        ;                // this is intentially left empty
    return it - str - 1; // -1 is to remove the null terminator
}

void commonLib::toUpper(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str &= ~32; // flips the 32 bit to off to uppercase
        str++;
    }
}

void commonLib::toLower(char *str)
{
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            *str |= 32; // flips the 32 bit to on to uppercase
        str++;
    }
}
