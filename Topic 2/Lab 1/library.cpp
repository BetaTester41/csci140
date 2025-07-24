#include <cstdlib>
#include "library.h"

int randRange(int start, int end)
{
    // range noninclusive of end
    // assume end > start
    
    /*int r{rand()};
    r = r % (end - start) + start;
    return r;*/

    return rand() % (end - start /*+1 if inclusive of end*/) + start;
}

double randDouble()
{
    return static_cast<double>(rand()) / RAND_MAX;
}

bool coinFlip()
{
    return static_cast<bool>(rand() & 1); // bitwise returns MSB which can only be 1 or 0
}