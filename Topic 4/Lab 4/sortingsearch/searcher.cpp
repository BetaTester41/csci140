#include "searcher.h"

static int binSearch(const int[], size_t, size_t, int);

int binSearch(const int array[], size_t size, int term)
{
    return binSearch(array, 0, size - 1, term);
}

int binSearch(const int array[], size_t start, size_t end, int term)
{
    int mid;

    if (start > end)
        return -1;

    mid = (start + end) >> 1;

    if (array[mid] == term)
        return mid;

    if (array[mid] < term)
        return binSearch(array, mid + 1, end, term);

    return binSearch(array, start, mid - 1, term);
}