#include <iostream>

#include "main.h"
#include "prime_sieve.h"

int main(int argc, char const *argv[])
{
    // getMaxPrime
    size_t maxPrimes = getMaxPrime();
    // call generate prime
    generatePrimes(maxPrimes);
    // print report
    printReport();

    return 0;
}

size_t getMaxPrime()
{
    size_t maxPrime;
    std::cout << "Enter the Max prime value: ";
    std::cin >> maxPrime;
    
    if (validMaxPrime(maxPrime)) return maxPrime;

    std::cout << "Max prime number cannot exceed " << MAX_PRIME_QTY << ". Try again!\n";
    return getMaxPrime();
}

bool validMaxPrime(size_t maxPrime) { return maxPrime <= MAX_PRIME_QTY; }