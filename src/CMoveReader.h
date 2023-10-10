#include "CBoard.h"
#include <iostream>

class MoveReader
{
    public:
    MoveReader(Board *board);
    // ~MoveReader();
    void read();

    private:
    Board *_board;
    std::string warning;
    void movePointerToRight();
    void movePointerToLeft();
    void pickRing();
    void putRing();
    void printInterface();
    bool decodeButton(int button);
};