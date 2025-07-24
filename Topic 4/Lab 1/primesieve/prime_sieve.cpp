#include <iostream>
#include <iomanip>

#include "prime_sieve.h"

#define COL_QTY 5
#define COL_WIDTH 10

static size_t primeQty;
// static bool sieve[MAX_PRIME_QTY + 1];
static bool* sieve; // using pointers instead

void generatePrimes(size_t primeQty)
{
    // get prime qty
    ::primeQty = primeQty;
    // set primeQty
    // init. the array
    initArray();
    // mark non primes
    markNonPrimes();
}

void printReport()
{
    std::cout << std::boolalpha;
    size_t count{0};

    for (size_t i = 2; i <= primeQty; ++i)
    {
        if (sieve[i])
        {
            std::cout << std::setw(COL_WIDTH) << i;
            ++count;
            if ((count % COL_QTY) == 0)
            {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "\nThe total number of prine <=" << primeQty << " is " << count << std::endl;
}

void initArray()
{
    /* Pointer Stuff */
    if (sieve != nullptr) delete[] sieve; // byebye nullptr exception
    sieve = new bool[primeQty+1];
    /* End of pointer stuff */
    for (size_t i = 2; i <= primeQty; ++i)
        sieve[i] = true;
}

void markNonPrimes()
{
    size_t nextPrime{2};
    while (nextPrime <= primeQty)
    {
        if (sieve[nextPrime])
            markMultiples(nextPrime);
        ++nextPrime; // whoops forgot abt that
    }
}

void markMultiples(size_t prime)
{
    for (size_t i = prime << 1; i <= primeQty; i += prime) // why is it prime + prime?
    {
        sieve[i] = false;
    }
}