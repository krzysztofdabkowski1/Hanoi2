#include "CHanoiResolver.h"

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    _numberOfTowers = _board.getTowerVector().size();
    int pointerdTower = _board.getPointedTower();
    
    int emptyTower;
    if (_board.hasTwoOrderedTowers(emptyTower))
    {
        std::cout<<"bly:"<<emptyTower<<std::endl;
        if (pointerdTower == 0)
            _board.moveRingTo(emptyTower);
    }
    // _board.setPointedTower(pointerdTower);
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};