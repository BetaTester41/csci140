// libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// header file
#include "dice_roll_sim.h"

// constants
#define FACE_QTY 6
#define TEST_QTY 10'000'000

// prototypes
void report(double[], size_t[]);

int main(int argc, char const *argv[])
{
    srand(0);
    // generate expected values
    double expected[(FACE_QTY * 2) + 1]{0, 0, 1.0 / 36, 2.0 / 36, 3.0 / 36, 4.0 / 36, 5.0 / 36, 6.0 / 36, 5.0 / 36, 4.0 / 36, 3.0 / 36, 2.0 / 36, 1.0 / 36};
    // values calculated by table vals

    // generate actual values
    size_t actual[(FACE_QTY * 2) + 1]{};
    for (size_t i = 0; i < TEST_QTY; i++)
    {
        ++actual[simulate2Rolls(FACE_QTY)];
    }

    // report
    report(expected, actual);

    return 0;
}

void report(double expected[], size_t actual[])
{
    std::cout << std::setw(5) << std::left << "Sum" << std::setw(10) << "Expected" << std::setw(10) << "Actual" << std::endl;
    for (size_t i = 2; i < (FACE_QTY * 2) + 1; i++)
    {
        std::cout << std::setw(5) << std::left << i << std::setw(10) << expected[i] << std::setw(10) << static_cast<double>(actual[i]) / TEST_QTY << std::endl;
    }
}
