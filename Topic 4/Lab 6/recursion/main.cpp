#include <iostream>
#include <unordered_map> // takes in key and value, with constant time of 1
#include "gcd.h"

#define TEST_VAL 50

size_t fib(size_t);
size_t fibIter(size_t);
size_t fact(size_t);
size_t sum(size_t);
size_t sum(size_t, size_t);
int sumArrary(const int[], size_t);

int main(int argc, char const *argv[])
{
    // std::cout << fib(TEST_VAL) << std::endl;
    std::cout << fibIter(TEST_VAL) << std::endl;
    // std::cout << fact(TEST_VAL) << std::endl;
    // std::cout << sum(TEST_VAL) << std::endl;
    // std::cout << sum(TEST_VAL - 10, TEST_VAL) << std::endl; // overloaded
    int array[]{1, 2, 3, 4, 5};
    size_t size{sizeof array / sizeof array[0]};
    std::cout << sumArrary(array, size) << std::endl;

    std::cout << gcdSub(10, 72) << std::endl;
    std::cout << gcdMod(10, 72) << std::endl;

    return 0;
}

size_t fib(size_t n)
{
    std::unordered_map<size_t, size_t> map; // created once, accessiable by all.

    if (n <= 1)
        return n;

    if (map.find(n) == map.end()) // search if it has been solved before, if not add it.
        map[n] = fib(n - 1) + fib(n - 2);

    return map[n];
}

/* Scary for loop start */
size_t fibIter(size_t n)
{
    size_t tail{0};

    for (size_t i = 0, front = 1, temp;
         i < n;
         temp = front, front += tail, tail = temp, ++i);

    return tail;
}
/* Scary for loop end */

size_t fact(size_t n)
{
    if (n <= 1)
        return 1;

    return n * fact(n - 1);
}

size_t sum(size_t n)
{
    if (n <= 1)
        return n;

    return n + sum(n - 1);
}

size_t sum(size_t start, size_t n)
{
    if (start >= n)
        return n;
    return start + sum(start + 1, n);
}

int sumArrary(const int array[], size_t size)
{
    if (size == 0)
        return array[0];
    return array[size - 1] + sumArrary(array, size - 1);
}
