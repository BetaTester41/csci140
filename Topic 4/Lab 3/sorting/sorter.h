#include <cstddef>

#ifndef SORTER_H
#define SORTER_H

void bubbleSort(int[], size_t);
void selectSort(int[], size_t);
void insertSort(int[], size_t);

size_t findMax(int[], size_t, size_t);
size_t findMin(int[], size_t, size_t);

void insertInto(int[], size_t);
void swap(int &, int &);

#endif /*SORTER_H*/