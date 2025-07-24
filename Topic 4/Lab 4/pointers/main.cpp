#include <iostream>

void prettyPrint(double[], size_t);
double *seqSearch(double[], size_t, double);

int main(int argc, char const *argv[])
{
    // int i{10};
    // pointer cannot be changed, data can
    // int* const ptr{&i};
    // data cannot be changed, pointer can
    // const int* ptr{&i}; or int const * ptr{&i};

    // nullptr = 0 = {}
    // const double *dbldbl{};

    // std::cout << i << ' ' << &i << ' ' << ptr << ' ' << &ptr << std::endl;
    // std::cout << sizeof ptr << std::endl;
    // std::cout << sizeof dbldbl << std::endl;

    // // to get the data the pointer is pointing to
    // std::cout << *ptr << std::endl;

    // std::cout << (*ptr)++ << std::endl;
    // std::cout << *(ptr++) << std::endl;

    // arrays are pointer varables; define addresses of items inside array
    double array[]{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    // prettyPrint(array, sizeof array / sizeof *array);

    // int i{10};
    // int j{10};
    // int *ptr{&i};
    // int *ptr2{&i};

    // (*ptr)++;

    // std::cout << std::boolalpha;
    // std::cout << (ptr == ptr2) << std::endl;
    // std::cout << (&ptr == &ptr2) << std::endl;
    // ptr2 = &j;
    // std::cout << (ptr == ptr2) << std::endl;

    std::cout << seqSearch(array, sizeof array / sizeof *array, 100.0) << std::endl;

    return 0;
}

void prettyPrint(double *array, size_t count)
{
    std::cout << "[ ";

    array += count;

    for (size_t i = 0; i < count; i++)
        std::cout << *(--array) << ' ';
    // you can also access using
    // *array++
    // *(array + i)
    // array[i]

    std::cout << "]\n";
}

double *seqSearch(double *array, size_t count, double term)
{
    for (size_t i = 0; i < count; ++i)
        if (array[i] == term)
            return &array[i];

    return nullptr;
}