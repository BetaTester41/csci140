#include <stdexcept>
#include "game.h"
#include "main.h"
#include "ui.h"
#include <iostream>

static size_t rowQty;
static size_t colQty;
static size_t userPos = 0;
int hazards[ROW_QTY*COL_QTY];

void gameInit(size_t rowQty, size_t colQty)
{
    ::rowQty = rowQty;
    ::colQty = colQty;
    generateHazards();
}

size_t getUserPos() { return userPos; }
void setUserPos(size_t pos) { userPos = pos; }

bool move(MoveDir dir)
{
    if (!validMove(dir))
    {
        // throw "Bad move >:(";
        // throw std::runtime_error("Bad move >:(");
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
    if (userPos == (rowQty * colQty) - 1)
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
    if (pos <= 1 || pos == rowQty || pos >= rowQty*colQty - 2 || pos == rowQty*(colQty-1)) return false;
    return true;
}

void generateHazards()
{
    // 20% for hazard 1
    // 5% for hazard 2
    srand(1);
    for (size_t i = 0; i < ROW_QTY*COL_QTY; ++i)
    {
        hazards[i] = 0;
        if (!checkPlacements(i)) continue;
        int r = rand() % 100;
        if (r < 20)
            hazards[i] = 1;
        else if (r < 25)
            hazards[i] = 2;
    }
}

int getHazard(size_t pos)
{
    return hazards[pos];
}

void checkHazards(size_t pos)
{
    if (hazards[pos] == 1)
    {
        std::cout << "Wormhole! Teleported to start." << std::endl;
        userPos = 0;
    }
    else if (hazards[pos] == 2)
    {
        std::cout << "Irradiated! Death..." << std::endl;
        userPos = rowQty * colQty + 1;
    }
}