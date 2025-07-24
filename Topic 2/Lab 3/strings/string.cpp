#include <iostream>

int main(int argc, char const *argv[])
{
    // char str[]{"hello\n"};
    // long long ll {18446744073709551615ll};
    // str[6] = 'y';

    // std::cout << str;
    for (size_t i = 0; i < 20; ++i)
    {
        if (i & 1) continue;
        std::cout << i << std::endl;
    }
    
    
    return 0;
}
