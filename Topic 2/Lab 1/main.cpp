// libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// header file
#include "library.h"

// constants
#define HEADS 1
#define TAILS 0
#define FACE_QTY 6
#define TEST_QTY 1'000'000

// prototypes
void report(size_t[]);

int main(int argc, char const *argv[])
{
    // srand(0);

    // size_t faces[FACE_QTY]{};

    // for (size_t i = 0; i < TEST_QTY; ++i) // loop 1 million times
    //     ++faces[randRange(0, FACE_QTY)];

    // report(faces);

    // std::cout << randDouble() << std::endl;

    size_t flips[2]{};
    for (size_t i = 0; i < TEST_QTY; ++i)
    {
        ++flips[coinFlip()];
    }
    
    std::cout << "Heads: " << flips[HEADS] << " Tails: " << flips[TAILS] << std::endl;
    return 0;
}

void report(size_t array[])
{
    // std::cout << "Face  |  Ratio\n";
    // std::cout << "-----------------\n";
    // for (size_t i = 0; i < FACE_QTY; i++)
    // {
    //     std::cout << i + 1 << "     |  " << static_cast <double> (array[i]) / TEST_QTY << std::endl;
    // }
    std::cout << std::setw(5) << std::left /*sticky?*/ << "Face" << std::setw(5) << "Ratio\n";
    for (size_t i = 0; i < FACE_QTY; i++)
    {
        std::cout << std::setw(5) << std::left << i + 1 << std::setw(5) << static_cast<double>(array[i]) / TEST_QTY << std::endl;
    }
}
