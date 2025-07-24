// libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int randRange(int start, int end)
{
    // return a random number between start and end
    return rand() % (end - start + 1 ) + start;
}

int simulate2Rolls(int faces)
{
    // roll 2 dices and add them together.
    return randRange(1, faces) + randRange(1, faces);
}