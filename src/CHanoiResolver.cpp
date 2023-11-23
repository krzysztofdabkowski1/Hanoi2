#include "CHanoiResolver.h"

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    _numberOfTowers = _board.getTowerVector().size();
    int pointerdTower = _board.getPointedTower();
    
    int unorderedTower, tmpTower;
    if (_board.hasTwoOrderedTowers(unorderedTower))
    {
        tmpTower = _board.getTowerWithGreatestBaseRing();
        if (pointerdTower != tmpTower)
        {
            _board.setPointedTower(tmpTower);
            pointerdTower = tmpTower;
        }
        _board.moveRingTo(unorderedTower);
        _tmpBaseTower = unorderedTower;
    }
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};