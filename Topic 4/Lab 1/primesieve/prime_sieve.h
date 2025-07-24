#include <cstddef>

#ifndef SIEVE_H
#define SIEVE_H

#define MAX_PRIME_QTY 100'000

void generatePrimes(size_t);
void printReport();
void initArray();
void markNonPrimes();
void markMultiples(size_t);

#endif /*SIEVE_H*/