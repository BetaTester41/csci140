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
void generateWormhole(size_t);
void checkHazards(size_t);
void generateMemoryModule();
size_t getVisited(size_t);
bool checkMemoryModule(size_t);
bool hasVisited(size_t);
bool hasWormhole(size_t);
bool hasIrradiation(size_t);
void setVisited(size_t);
bool checkAdjacent(size_t);
void grabMemoryModule();

#endif /*GAME_H*/