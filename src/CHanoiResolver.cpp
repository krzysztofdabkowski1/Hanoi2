#include "CHanoiResolver.h"
#include <algorithm>

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    _numberOfTowers = _board.getTowerVector().size();
    int pointedTower = _board.getPointedTower();
    
    std::vector<int> orderedTowers, unorderedTowers;
    _board.getOrderedTowers(orderedTowers, unorderedTowers);
    std::vector<std::pair<int,int>> sortedTowers;
    _board.getTowersSortedByBaseRing(sortedTowers);
    int lowTower   = sortedTowers.front().first;
    int largeTower = sortedTowers.back().first;
    if (orderedTowers.size() == 1)
    {
        int tmpTower = _board.getTowerWithGreatestBaseRing();
        int baseOfSubtower = _board.getBaseRingSizeOfSubtower(tmpTower);
        std::cout<<baseOfSubtower<<std::endl;
        std::cout<<lowTower<<std::endl;
        std::cout<<unorderedTowers[1]<<std::endl;
        std::cout<<orderedTowers[0]<<std::endl;
        if (baseOfSubtower > 1 && _board.getTowerVector()[lowTower]->topRingSize() == baseOfSubtower + 1 && _board.getTowerVector()[tmpTower]->topRingSize() == 1)
        {
            if (pointedTower != tmpTower)
            {
                _board.setPointedTower(tmpTower);
                pointedTower = tmpTower;
            }
        
            if (baseOfSubtower % 2 == 0)
            {
                _board.moveRingTo(unorderedTowers[1]);
                _tmpBaseTower = unorderedTowers[1];  
            }
            else
            {
                _board.moveRingTo(orderedTowers[0]);
                _tmpBaseTower = orderedTowers[0];                          
            }
        }
        else
        {
            if (pointedTower != tmpTower)
            {
                _board.setPointedTower(tmpTower);
                pointedTower = tmpTower;
            }

            if (_board.getTowerVector()[tmpTower]->topRingSize() + 1 == _board.getTowerVector()[orderedTowers[0]]->topRingSize())
            {
                int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
                if (_board.getTowerVector()[destTower]->topRingSize() + 1 == _board.getTowerVector()[tmpTower]->topRingSize())
                {
                    if (pointedTower != destTower)
                    {
                        _board.setPointedTower(destTower);
                        pointedTower = destTower;
                    }
                    _board.moveRingTo(tmpTower);
                    _tmpBaseTower = tmpTower;
                }
                else
                {
                    _board.moveRingTo(orderedTowers[0]);
                    _tmpBaseTower = orderedTowers[0];
                }
            }
            else
            {
                _board.moveRingTo(unorderedTowers[0]);
                _tmpBaseTower = unorderedTowers[0];
            }       
        }
        
    }
    else if (orderedTowers.size() == 2)
    {
        // orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), lowTower), orderedTowers.end());
        // orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), largeTower), orderedTowers.end());
        int baseOfSubtower = _board.getBaseRingSizeOfSubtower(unorderedTowers[0]);
        int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
        int startTower = _board.getTowerWithGreatestBaseRing();
        if (_board.getTowerVector()[destTower]->topRingSize() == _board.getTowerVector()[lowTower]->topRingSize() + 1  
            && startTower != destTower)
        {
            if (pointedTower != lowTower)
            {
                _board.setPointedTower(lowTower);
                pointedTower = lowTower;
            }
            _board.moveRingTo(destTower);
            _tmpBaseTower = destTower;  
        }
        else if (_board.getTowerVector()[destTower]->topRingSize() + 1 == _board.getTowerVector()[lowTower]->topRingSize() 
            && startTower != destTower)
        {
            if (pointedTower != lowTower)
            {
                _board.setPointedTower(lowTower);
                pointedTower = lowTower;
            }
            _board.moveRingTo(startTower);
            _tmpBaseTower = startTower;             
        }
        else if (baseOfSubtower > 0)
        {
            if (pointedTower != unorderedTowers[0])
            {
                _board.setPointedTower(unorderedTowers[0]);
                pointedTower = unorderedTowers[0];
            }

            if (_board.getTowerVector()[unorderedTowers[0]]->topRingSize() + 1 == _board.getTowerVector()[orderedTowers[0]]->topRingSize())
            {
                _board.moveRingTo(orderedTowers[0]);
                _tmpBaseTower = orderedTowers[0];
            }
            else if (_board.getTowerVector()[unorderedTowers[0]]->topRingSize() + 1 == _board.getTowerVector()[orderedTowers[1]]->topRingSize())
            {
                _board.moveRingTo(orderedTowers[1]);
                _tmpBaseTower = orderedTowers[1];
            }
        }
        else
        {
            if (pointedTower != startTower)
            {
                _board.setPointedTower(startTower);
                pointedTower = startTower;
            }
            _board.moveRingTo(unorderedTowers[0]);
            _tmpBaseTower = unorderedTowers[0];
        }

    }
    else if (orderedTowers.size() == 3) 
    {
        if (pointedTower != lowTower)
        {
            _board.setPointedTower(lowTower);
            pointedTower = lowTower;
        }

        orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), lowTower), orderedTowers.end());
        orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), largeTower), orderedTowers.end());
        if( _board.getTowerVector()[lowTower]->hasOneRing())
        {
            _board.moveRingTo(orderedTowers[0]);
            _tmpBaseTower = orderedTowers[0];
        }
        else
        {
            int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
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
    else
    {
        int startTower = _board.getTowerWithGreatestBaseRing();
        int baseOfSubtower = _board.getBaseRingSizeOfSubtower(startTower);
    }
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};