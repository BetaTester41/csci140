#include <iostream>

/*
bad code
using namespace std;
*/

using std::cout; // good names!

size_t count{1000};

namespace std
{
    void printArray(int[], size_t &); // prototype (decloration of a funciton, but no definition) AKA stub function
}

int main(int argc, char const *argv[])
{
    int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int count{sizeof(array) / sizeof(array[0])};
    count = sizeof(array) / sizeof(array[0]);

    { // innerscope
        size_t count(100);
        std::cout << ::count << std::endl; // ::VARNAME = refrence global count
    }

    std::cout << count << std::endl; // can use cout if namespace is implmemented
    // printArray(array, sizeof(array) / sizeof(array[0]));
    // printArray(array, count);
    std::printArray(array, count);

    std::cout << count << std::endl;

    return 0;
}

// implementation of printArray
namespace std
{
    void printArray(int a[], size_t &count) // & means refrence / mem area (can change count now)
    {
        // std::cout << sizeof(a) << std::endl;
        std::cout << "[ ";
        for (size_t i = 0; i < count; ++i) // ++i is more efficent than i++!!!
            std::cout << a[i] << ' ';      // single quote for single charater (char v. string)
        std::cout << "]\n";

        count = 0; // does not affect count in the main method, local to this
    }
}

// scope never up access down, always down access up

/* you can also use this
void std::printArray(int a[], size_t &count) // & means refrence / mem area (can change count now)
{
    // std::cout << sizeof(a) << std::endl;
    std::cout << "[ ";
    for (size_t i = 0; i < count; ++i) // ++i is more efficent than i++!!!
        std::cout << a[i] << ' ';      // single quote for single charater (char v. string)
    std::cout << "]\n";
    count = 0; // does not affect count in the main method, local to this
}
*/