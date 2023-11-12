#include "CHanoiResolver.h"

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    _numberOfTowers = _board.getTowerVector().size();
    int pointerdTower = _board.getPointedTower();
     // make next step
    _board.setPointedTower(pointerdTower);
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};