#include <iostream>

size_t gcdSub(size_t a, size_t b)
{
    if (a == b)
        return a;
    if (a > b)
        return gcdSub(a - b, b);
    return gcdSub(a, b - a);
}

size_t gcdMod(size_t a, size_t b)
{
    if (b == 0)
        return a;
    if (a > b)
        return gcdMod(b, a % b);
    return gcdMod(a, b % a);
}