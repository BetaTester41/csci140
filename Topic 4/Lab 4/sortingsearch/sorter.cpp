#include "sorter.h"

void bubbleSort(int array[], size_t count)
{
    size_t a{};
    size_t b{};
    bool swapped;

    for (int i = count - 1; i >= 1; i--)
    {
        swapped = false;
        for (size_t j = 0; j < i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectSort(int array[], size_t count)
{
    int min;
    for (size_t i = 0; i < count - 1; i++)
    {
        min = findMin(array, i, count - 1);
        if (min != i)
            swap(array[i], array[min]);
    }
}

void insertSort(int array[], size_t count)
{
    for (size_t i = 1; i < count; i++)
        insertInto(array, i);
}

size_t findMax(int array[], size_t start, size_t end)
{
    // assume start <= end
    size_t maxIdx{start};
    for (size_t i = start + 1; i <= end; i++)
        if (array[i] > array[maxIdx])
            maxIdx = i;

    return maxIdx;
}

size_t findMin(int array[], size_t start, size_t end)
{
    // assume start <= end
    size_t minIdx{start};
    for (size_t i = start + 1; i <= end; i++)
        if (array[i] < array[minIdx])
            minIdx = i;

    return minIdx;
}

void insertInto(int array[], size_t unsortedIdx)
{
    int leftIdx{unsortedIdx - 1};
    int temp{array[unsortedIdx]};

    while (leftIdx >= 0 && temp < array[leftIdx])
    {
        array[leftIdx + 1] = array[leftIdx];
        --leftIdx;
    }
    array[leftIdx + 1] = temp;
}

void swap(int &a, int &b)
{
    if (a == b)
        return;
    a ^= b;
    b ^= a;
    a ^= b;
}