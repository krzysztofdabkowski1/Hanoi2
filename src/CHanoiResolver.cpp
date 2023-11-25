#include "CHanoiResolver.h"

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    _numberOfTowers = _board.getTowerVector().size();
    int pointerdTower = _board.getPointedTower();
    
    std::vector<int> unorderedTower;
    int tmpTower;
    if (_board.hasTwoOrderedTowers(unorderedTower))
    {
        tmpTower = _board.getTowerWithGreatestBaseRing();
        if (pointerdTower != tmpTower)
        {
            _board.setPointedTower(tmpTower);
            pointerdTower = tmpTower;
        }
        _board.moveRingTo(unorderedTower[0]);
        _tmpBaseTower = unorderedTower[0];
    }
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};