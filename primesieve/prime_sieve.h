#ifndef PRIME_SIEVE_H
#define PRIME_SIEVE_H

#include <string>

void start();
void setToTrue();
int askForNumber(std::string);
void sieveNum(int);
bool isValidNum(int);
int findNextPrime(int, int);
void printReport(int);

#endif // PRIME_SIEVE_H