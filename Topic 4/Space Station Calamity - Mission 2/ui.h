#include <cstddef>
#include <string>

#ifndef UI_H // if not defined
#define UI_H // then define it

void start(size_t, size_t);
void printBoard();

bool processInput(char);
void printBorder();
void printRow(size_t);
std::string makeInfo(size_t);
bool promptReplay();

size_t getUserRow();
size_t getUserCol();

#endif /*UI_H*/