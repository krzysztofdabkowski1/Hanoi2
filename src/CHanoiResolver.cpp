#include "CHanoiResolver.h"
#include <algorithm>

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    _numberOfTowers = _board.getTowerVector().size();
    int pointedTower = _board.getPointedTower();
    
    std::vector<int> orderedTowers, unorderedTowers;
    _board.getOrderedTowers(orderedTowers, unorderedTowers);
    if (orderedTowers.size() == 1 )
    {
        int tmpTower = _board.getTowerWithGreatestBaseRing();
        if (pointedTower != tmpTower)
        {
            _board.setPointedTower(tmpTower);
            pointedTower = tmpTower;
        }
        _board.moveRingTo(unorderedTowers[0]);
        _tmpBaseTower = unorderedTowers[0];       
    }
    else if (orderedTowers.size() == 2)
    {
        int tmpTower = _board.getTowerWithGreatestBaseRing();
        if (pointedTower != tmpTower)
        {
            _board.setPointedTower(tmpTower);
            pointedTower = tmpTower;
        }
        _board.moveRingTo(unorderedTowers[0]);
        _tmpBaseTower = unorderedTowers[0];
    }
    else if (orderedTowers.size() == 3) 
    {
        int baseRingSizeInLowTower;
        std::vector<std::pair<int,int>> sortedTowers;
        _board.getTowersSortedByBaseRing(sortedTowers);
        int lowTower   = sortedTowers.front().first;
        int largeTower = sortedTowers.back().first;
        orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), lowTower), orderedTowers.end());
        orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), largeTower), orderedTowers.end());
        if (pointedTower != lowTower)
        {
            _board.setPointedTower(lowTower);
            pointedTower = lowTower;
        }
        if( _board.getTowerVector()[lowTower]->hasOneRing())
        {
            _board.moveRingTo(orderedTowers[0]);
            _tmpBaseTower = orderedTowers[0];
        }
        else
        {
            int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
            std::cout<<"baseRingSize:"<<_board.getTowerVector()[lowTower]->baseRingSize()<<std::endl;
            std::cout<<"getTowerWithRingSize:"<<destTower<<std::endl;
            if (_board.getTowerVector()[destTower]->hasOneRing())
            {
                if (_board.getTowerVector()[lowTower]->size() % 2 == 1)
                {
                    _board.moveRingTo(destTower);
                    _tmpBaseTower = destTower;  
                }
                else
                {
                    _board.moveRingTo(largeTower);
                    _tmpBaseTower = largeTower;                          
                }
            }
        }
        
    }
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};