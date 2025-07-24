#include <iostream>

void moveDisk(int, char, char);
void moveStack(int, char, char, char);

int main(int argc, char const *argv[])
{
    moveStack(8, 'A', 'C', 'B');
    return 0;
}

void moveDisk(int disk, char from, char to)
{
    static size_t count{0};
    std::cout << ++count << ") Move disk " << disk << " from peg " << from << " to peg " << to << std::endl;
}

void moveStack(int diskQty, char from, char to, char temp)
{
    if (diskQty == 1)
    {
        moveDisk(diskQty, from, to);
        return;
    }

    moveStack(diskQty - 1, from, temp, to);
    moveDisk(diskQty, from, to);
    moveStack(diskQty - 1, temp, to, from);
}
