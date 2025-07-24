#include <iostream>

#include "ui.h"
#include "game.h"

static size_t rowQty;
static size_t colQty;
bool alive{true};

void start(size_t rowQty, size_t colQty)
{
    ::rowQty = rowQty;
    ::colQty = colQty;

    gameInit(rowQty, colQty);
    char input;
    bool lastMoveValid{true};

    while (alive)
    {
        if (lastMoveValid) printBoard();
        std::cout << "Enter move (w, a, s, d, e[exit]): ";
        std::cin >> input;
        lastMoveValid = processInput(input);
        if (checkEndGame()) alive = false;
    }
}

bool processInput(char input)
{
    bool lastMoveValid{true};
    switch (input)
    {
    case 'w':
        lastMoveValid = move(MoveDir::UP);
        break;
    case 'a':
        lastMoveValid = move(MoveDir::LEFT);
        break;
    case 's':
        lastMoveValid = move(MoveDir::DOWN);
        break;
    case 'd':
        lastMoveValid = move(MoveDir::RIGHT);
        break;
    case 'e':
        alive = false;
        lastMoveValid = false;
        std::cout << "Exiting game..." << std::endl;
        break;
    default:
        std::cout << "Invalid input. Try again." << std::endl;
        lastMoveValid = false;
        break;
    }
    return lastMoveValid;
}

void printBoard()
{
    for (size_t i = 0; i < rowQty; ++i)
    {
        printBorder();
        printRow(i);
    }
    printBorder(); // to finish the bottom row
}

void printBorder()
{
    for (size_t i = 0; i < colQty; ++i)
        std::cout << "----";

    std::cout << "-\n";
}

void printRow(size_t row)
{
    size_t userRow{getUserRow()};
    size_t userCol{getUserCol()};
    char u;

    for (size_t i = 0; i < colQty; ++i)
    {
        u = (userRow == row && userCol == i) ? 'U' : ' ';
        // int u = getHazard(row * colQty + i); // debug
        std::cout << "| " << u << ' ';
    }

    std::cout << "|\n";
}

size_t getUserRow() { return getUserPos() / colQty; }

size_t getUserCol() { return getUserPos() % colQty; }