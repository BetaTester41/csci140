#include <iostream>
#include "sorter.h"

void printArray(int[], size_t);

int main(int argc, char const *argv[])
{
    int array[]{8, 6, 1, 3, 9, 2, 5, 7, 4};
    // int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    size_t size{sizeof(array) / sizeof(array[0])};

    printArray(array, size);
    // bubbleSort(array, size);
    // selectSort(array, size);
    insertSort(array, size);
    printArray(array, size);

    return 0;
}

void printArray(int array[], size_t count)
{
    std::cout << "[ ";

    for (size_t i = 0; i < count; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << "]\n";
}