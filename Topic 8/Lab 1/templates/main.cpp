#include <iostream>
#include <array>
#include <vector>

// START OF TEMPLATES

template <typename T, size_t S>
void printArray(const T arr[] /*, size_t count*/)
{
    std::cout << "[ ";

    for (size_t i = 0; i < S; ++i)
        std::cout
            << arr[i] << ' ';

    std::cout << "]\n";
}

template <typename T> // can print all iterable objects
void printArray(const T container /*, size_t count*/)
{
    std::cout << "[ ";

    for (auto& item : container)
        std::cout << item << ' ';

    std::cout << "]\n";
}

// END OF TEMPLATES

int main(int argc, char const *argv[])
{
    double array[]{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::array<double, 9> stdArray{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<double> stdVector{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<double> vectorSize(25);

    std::cout << "Regular Array:\n";
    printArray<double, 9>(array);
    std::cout << "Standard Array:\n";
    printArray<std::array<double, 9>>(stdArray);
    std::cout << "Standard Vector:\n";
    printArray<std::vector<double>>(stdVector);

    std::cout << "Custom Range Based Loop:\n";
    for (auto i = stdVector.begin(); i < stdVector.end(); i++) // just like the range based for loop.
    {
        std::cout << *i << ' ';
    }

    return 0;
}
