#include <iostream>
#include <iomanip>
#include "prime_sieve.h"

#define MAX_N_VAL 100'000

bool isPrime[MAX_N_VAL + 1];

void start()
{
    int num{};
    num = askForNumber("Enter a number between between 2 and 100,000: ");
    isPrime[0] = false;
    isPrime[1] = false;
    setToTrue();
    sieveNum(num);
    printReport(num);
}

void setToTrue()
{
    for (int i = 0; i <= MAX_N_VAL; i++)
    {
        isPrime[i] = true;
    }
}

int askForNumber(std::string prompt)
{
    bool isValid{false};
    int input{};

    while (!isValid)
    {
        std::cout << prompt;
        std::cin >> input;
        isValid = isValidNum(input);
    }
    return input;
}

bool isValidNum(int num)
{
    if (num > 2 && num < MAX_N_VAL)
        return true;
    return false;
}

void sieveNum(int num)
{
    int p{2};
    while (p < num)
    {
        for (size_t i = p * p; i < num; i += p) // i used i=p instead of i=p*p in the exam
        {
            isPrime[i] = false;
        }
        p = findNextPrime(p, num);
    }
}

int findNextPrime(int p, int num)
{
    for (size_t i = p + 1; i < num; i++)
    {
        if (isPrime[i])
            return i;
    }
    return num;
}

void printReport(int num)
{
    int count{0}; // not implemented
    bool lastNewLine{false}; // not implemented

    for (size_t i = 2; i < num; i++)
    {
        if (isPrime[i])
        {
            std::cout << std::right << std::setw(10) << i;
            ++count; // not implemented
            lastNewLine = false; // not implemented
        }
        if (count % 5 == 0 && !lastNewLine) // not implemented
            std::cout << std::endl;
            lastNewLine = true; // not implemented
    }
    std::cout << "\nThere are " << count << " prime numbers between 2 and " << num << std::endl; // not implemented
}
