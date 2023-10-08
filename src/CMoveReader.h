#include "CBoard.h"

class MoveReader
{
    public:
    MoveReader(Board *board);
    // ~MoveReader();
    void read();

    private:
    Board *_board;
    void movePointerToRight();
    void movePointerToLeft();
    void pickRing();
    void putRing();
};