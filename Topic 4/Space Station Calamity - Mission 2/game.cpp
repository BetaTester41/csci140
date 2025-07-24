#include <stdexcept>
#include "game.h"
#include "main.h"
#include "ui.h"
#include <iostream>

#define WORMHOLE_PCT 25
#define IRRADIATED_PCT 10

static size_t rowQty;
static size_t colQty;
static size_t userPos{ROW_QTY*COL_QTY-1};
bool hasMemoryModule{false};
size_t memoryModulePos{};

int wormholeDest[ROW_QTY*COL_QTY]; // when you move check irradiated
size_t information[ROW_QTY*COL_QTY]; // check me second


void gameInit(size_t rowQty, size_t colQty)
{
    ::rowQty = rowQty;
    ::colQty = colQty;
    generateHazards();
    generateMemoryModule();
    setVisited(userPos);
}

size_t getUserPos() { return userPos; }
void setUserPos(size_t pos) { userPos = pos; }

bool move(MoveDir dir)
{
    if (!validMove(dir))
    {
        std::cout << "Error, invalid Move!!!\nTry again." << std::endl;
        return false;
    }

    switch (dir)
    {
    case MoveDir::UP:
        userPos -= colQty;
        break;
    case MoveDir::DOWN:
        userPos += colQty;
        break;
    case MoveDir::LEFT:
        --userPos;
        break;
    case MoveDir::RIGHT:
        ++userPos;
        break;
    }
    checkHazards(userPos);
    setVisited(userPos);
    return true;
}

bool validMove(MoveDir dir)
{
    switch (dir)
    {
    case MoveDir::UP:
        return validUpMove();
    case MoveDir::DOWN:
        return validDownMove();
    case MoveDir::LEFT:
        return validLeftMove();
    default:
        return validRightMove();
    }
}

bool validUpMove()
{
    return userPos >= colQty;
}

bool validDownMove()
{
    return userPos < (rowQty * (colQty - 1));
}

bool validLeftMove()
{
    return (userPos % colQty) != 0;
}

bool validRightMove()
{
    return (userPos % colQty) < (colQty - 1);
}

bool checkEndGame()
{
    if (hasMemoryModule && (userPos == (rowQty * colQty) - 1))
    {
        printBoard();
        std::cout << "You win!" << std::endl;
        return true;
    }
    if (userPos == rowQty * colQty + 1)
    {
        printBoard();
        std::cout << "You lose!" << std::endl;
        return true;
    }
    return false;
}

bool checkPlacements(size_t pos)
{
    if (pos >= rowQty*colQty - 2 || pos == rowQty*(colQty-1)) return false;
    if (wormholeDest[pos] > -1) return false;
    if (information[pos] & 0x02) return false;
    return true;
}

void generateHazards()
{
    // 20% for hazard 1
    // 5% for hazard 2
    srand(1);
    for (size_t i = 0; i < ROW_QTY*COL_QTY; ++i)
    {
        information[i] = 0x00;
        wormholeDest[i] = -1;
        if (!checkPlacements(i)) continue;
        int r = rand() % 100;
        if (r < WORMHOLE_PCT)
            generateWormhole(i);
        else if (r < WORMHOLE_PCT+IRRADIATED_PCT)
            information[i] |= 0x02;
    }
}

void generateWormhole(size_t i)
{
    size_t dest = rand() % (ROW_QTY*COL_QTY);
    while (!checkPlacements(dest) || dest == i)
        dest = rand() % (ROW_QTY*COL_QTY);
    wormholeDest[i] = dest;
    information[i] |= 0x01;
}


void checkHazards(size_t pos)
{
    if (wormholeDest[pos] > -1)
    {
        std::cout << "Wormhole! Teleported to " << wormholeDest[pos] - 1 << std::endl;
        userPos = wormholeDest[pos];
        checkHazards(userPos);
    }
    else if (information[pos] & 0x02)
    {
        std::cout << "Irradiated! Death..." << std::endl;
        userPos = rowQty * colQty + 1;
    }
}

void generateMemoryModule()
{
    srand(10);
    memoryModulePos = rand() % (ROW_QTY*COL_QTY);
    while (!checkPlacements(memoryModulePos))
        memoryModulePos = rand() % (ROW_QTY*COL_QTY);
    srand(1); // reset seed
}

size_t getVisited(size_t pos)
{
    return information[pos];
}

bool checkMemoryModule(size_t pos)
{
    return (pos == memoryModulePos);
}

bool hasVisited(size_t pos)
{
    return (information[pos] & 0x04);
    std::cout << (information[pos] & 0x04) << std::endl;
}

bool hasWormhole(size_t pos)
{
    return (information[pos] & 0x01);
}

bool hasIrradiation(size_t pos)
{
    return (information[pos] & 0x02);
}

void setVisited(size_t pos)
{
    if (pos > ROW_QTY*COL_QTY-1) return;
    information[pos] |= 0x04;
}

bool checkAdjacent(size_t pos)
{
    // check if pos is adjacent to userPos
    if (pos == userPos) return true;
    if (pos == userPos - 1) return true;
    if (pos == userPos + 1) return true;
    if (pos == userPos - colQty) return true;
    if (pos == userPos + colQty) return true;
    return false;
}

void grabMemoryModule()
{
    hasMemoryModule = true;
    std::cout << "Memory Module acquired!" << std::endl;
    memoryModulePos = -1;
}