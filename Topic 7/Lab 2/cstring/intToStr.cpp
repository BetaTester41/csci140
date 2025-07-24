#include <iostream>
#include <cstdlib> // includes itoa and atoi functions

namespace commonLib
{
    char *itoa(int);
    void itoa(int, char[]);
    void swap(char *, char *);
    void revstr(char *);
    size_t strlen(const char *);
}

int main(int argc, char const *argv[])
{
    char str[]{"-125"};
    int i{atoi(str)};

    std::cout << i << std::endl;

    char *val{commonLib::itoa(i)};
    // std::cout << i << std::endl;
    std::cout << val << std::endl;

    return 0;
}

char *commonLib::itoa(int i)
{
    char *str{new char[11]{}};
    char *it{str};
    bool rev = 0;

    if (i == INT_MIN) throw new std::runtime_error("BOO YO SUCK");

    if (i < 0)
    {
        *(it++) = '-';
        rev = 1;
        i = 0 - i;
    }

    if (i == 0)
    {
        *str = '0';
        return str;
    }

    itoa(i, it);
    revstr(str + rev);
    return str;
}

void commonLib::itoa(int i, char it[])
{
    char temp;
    while (i != 0)
    {
        temp = static_cast<char>(i % 10 + 48); // get the last digiut
        i /= 10;
        *(it++) = temp;
    }
}

void commonLib::swap(char *a, char *b)
{
    char temp{*a};
    *a = *b;
    *b = temp;
}

void commonLib::revstr(char *str)
{
    size_t len{strlen(str)};
    char *end{str + len - 1};

    while (str < end)
    {
        swap(str, end);
        str++;
        end--;
    }
}

size_t commonLib::strlen(const char *str)
{
    const char *it{str};
    while (*(it++))
        ;                // this is intentially left empty
    return it - str - 1; // -1 is to remove the null terminator
}