#include <iostream>
#include <iomanip>
#include <cmath>

#include "dice_sim.h"

#define FACE_QTY 6
#define ARRAY_SIZE 13
#define SAMPLE_SIZE 10'000'000
#define SUM_WIDTH 5
#define DATA_WIDTH 10

double expected[ARRAY_SIZE]{};
double actual[ARRAY_SIZE]{};

void runSim()
{
    // calc expected
    initializeExpected();
    // run expermient
    runExperiment();
    // print the report
    printReport();
}

void initializeExpected()
{
    const double COUNT = FACE_QTY * FACE_QTY;
    for (size_t i = 1; i <= FACE_QTY; ++i)
        for (size_t j = 1; j <= FACE_QTY; ++j)
            ++expected[i + j];

    for (size_t i = 2; i < ARRAY_SIZE; ++i)
        expected[i] /= COUNT;
}

void runExperiment()
{
    for (size_t i = 0; i < SAMPLE_SIZE; ++i)
        ++actual[randRange(1, 6) + randRange(1, 6)];

    for (size_t i = 2; i < ARRAY_SIZE; ++i)
        actual[i] /= SAMPLE_SIZE;
}

void printReport()
{
    printHeader();
    printTable();
}

size_t randRange(size_t start, size_t end)
{
    return rand() % (end - start + 1) + start;
}

void printHeader()
{
    std::cout << std::left << std::setw(SUM_WIDTH) << "Sum"
              << std::setw(DATA_WIDTH) << "Expect"
              << std::setw(DATA_WIDTH) << "Actual" << std::endl;
}

void printTable()
{
    std::cout << std::setprecision(DATA_WIDTH - 4);
    // set precision works, bigger number needed
    for (size_t i = 2; i < ARRAY_SIZE; ++i)
    {
        std::cout << std::left << std::setw(SUM_WIDTH) << i
                  << std::setw(DATA_WIDTH) << expected[i]
                  << std::setw(DATA_WIDTH) << actual[i] << std::endl;
    }
}

double roundPrecision(double val, size_t precision)
{
    val = round(val* pow(10, precision));
    return val / pow(10, precision);
}