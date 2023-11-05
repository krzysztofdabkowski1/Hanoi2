#ifndef Game_H
#define Game_H

#include "CBoard.h"
#include <iostream>

class Game
{
    public:
    Game(Board *board);
    void run();

    private:
    Board *_board;
    std::string warning;
    void movePointerToRight();
    void movePointerToLeft();
    void pickRing();
    void putRing();
    void printInterface();
    bool decodeButton(int button);
    bool gameOver(); 
    void printGameOverBanner();
    void printHelpInfo();
};
#endif