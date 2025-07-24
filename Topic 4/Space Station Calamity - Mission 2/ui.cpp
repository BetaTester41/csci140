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
        if (lastMoveValid)
            printBoard();
        std::cout << "Enter move (w, a, s, d, ";
        if (checkMemoryModule(getUserPos()))
            std::cout << "g[grab], ";
        std::cout << "e[exit]): ";
        std::cin >> input;
        lastMoveValid = processInput(input);
        if (checkEndGame())
        {
            alive = promptReplay();
            if (alive)
                gameInit(rowQty, colQty);
        }
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
        std::cout << "Exiting game..." << std::endl;
        break;
    case 'g':
        grabMemoryModule();
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
        std::cout << "------";

    std::cout << "-\n";
}

void printRow(size_t row)
{
    std::string u;

    for (size_t i = 0; i < colQty; ++i)
    {
        size_t pos = row * colQty + i;
        u = makeInfo(pos);

        std::cout << "| " << u << ' ';
    }

    std::cout << "|\n";
}

std::string makeInfo(size_t pos)
{
    std::string u;
    if (getUserPos() == pos)
    {
        u = "U";
        u += (checkMemoryModule(pos)) ? "M" : "";
    }
    else if (hasVisited(pos))
        u = "*";
    else
        u = " ";
    if (checkAdjacent(pos))
    {
        u += (hasWormhole(pos)) ? "W" : " ";
        u += (hasIrradiation(pos)) ? "I" : " ";
    }
    else
        u += "  ";
    if (u.length() > 3)
        u = u.substr(0, 3);
    return u;
}

bool promptReplay()
{
    char input;
    std::cout << "Play again? (y/n): ";
    std::cin >> input;
    input = tolower(input);
    setUserPos(rowQty * colQty - 1);
    return (input == 'y');
}

size_t getUserRow() { return getUserPos() / colQty; }

size_t getUserCol() { return getUserPos() % colQty; }