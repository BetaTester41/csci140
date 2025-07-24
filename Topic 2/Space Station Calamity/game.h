#include <cstddef>

#ifndef GAME_H // if not defined
#define GAME_H // then define it

enum class MoveDir { UP, DOWN, LEFT, RIGHT };

void gameInit(size_t, size_t);
size_t getUserPos();
void setUserPos(size_t);
bool move(MoveDir);
bool validMove(MoveDir);
bool validUpMove();
bool validDownMove();
bool validLeftMove();
bool validRightMove();
bool checkEndGame();
bool checkPlacements(size_t);
void generateHazards();
int getHazard(size_t);
void checkHazards(size_t);

#endif /*GAME_H*/