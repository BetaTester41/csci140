#include <iostream>
#include <array>
#include <vector>

void prettyPrint(double[], size_t);
void prettyPrint(std::array<int, 10>);
void prettyPrint(std::vector<int>);

int main(int argc, char const *argv[])
{
    double lower{-10};
    double a[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double higher{100};

    std::array<int, 10> staticA{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // can hold any of 1 type of data
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    v.push_back(100); // add to the end

    // size_t count{sizeof(a) / sizeof(a[0])}; // size of array divided by size of each item

    // prettyPrint(staticA); // print std::array
    prettyPrint(v); // print std::vector

    std::cout << sizeof(v) << std::endl;

    // std::cout << count << std::endl; // # of elements

    // prettyPrint(a, count + 10); // print overflow memory

    // a[13] = -1'000'000; // overwriting memory location

    // std::cout << std::fixed /*print in normal notaiton only (sticky) << std::scientific  set to scientific*/ << lower << std::endl;

    return 0;
}

void prettyPrint(double array[], size_t count)
{
    std::cout << "[ ";

    for (size_t i = 0; i < count; i++)
        std::cout << array[i] << ' ';

    std::cout << "]\n";
}

void prettyPrint(std::array<int, 10> a)
{
    std::cout << "[ ";

    for (auto i : a) // for each element a, store ref. location in i (ALSO CANNOT EXCEED BOUNDS OF ARRAY)
        std::cout << i << ' ';

    // for (size_t i = 0; i < a.size(); ++i)
    //     std::cout << a[i] << ' ';
    std::cout << "]\n";
}

void prettyPrint(std::vector<int> a)
{
    std::cout << "[ ";

    for (auto i : a) // for each element a, store ref. location in i
        std::cout << i << ' ';

    // for (size_t i = 0; i < a.size(); ++i)
    //     std::cout << a[i] << ' ';
    std::cout << "]\n";
}