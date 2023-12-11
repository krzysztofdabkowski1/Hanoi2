#include "CHanoiResolver.h"
#include <algorithm>

#define FIRST  0
#define SECOND 1
#define THIRD  2

void HanoiResolver::MakeNextStep(Board& _board) 
{ 
    loadTowerStatVector(_board);

    if (tower[FIRST].baseRingSize == _board.getNumberOfRings())
    {
        if (tower[FIRST].hasAllRings)
            moveRing(_board, FIRST, SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[SECOND].topRingSize == 1 &&
                 tower[THIRD].isEmpty)
            moveRing(_board, FIRST, THIRD);
        else if (tower[FIRST].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[THIRD].topRingSize == 1 &&
                 tower[SECOND].isEmpty)
            moveRing(_board, FIRST, SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[THIRD].topRingSize + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);        
    }



    tower.clear();
    // _numberOfTowers = _board.getTowerVector().size();
    // int pointedTower = _board.getPointedTower();
    
    // std::vector<int> orderedTowers, unorderedTowers;
    // _board.getOrderedTowers(orderedTowers, unorderedTowers);
    // std::vector<std::pair<int,int>> sortedTowers;
    // _board.getTowersSortedByBaseRing(sortedTowers);
    // int lowTower   = sortedTowers.front().first;
    // int largeTower = sortedTowers.back().first;
    // if (orderedTowers.size() == 1)
    // {
    //     int tmpTower = _board.getTowerWithGreatestBaseRing();
    //     int baseOfSubtower = _board.getBaseRingSizeOfSubtower(unorderedTowers[0]);
    //     int baseOfSubtower2 = _board.getBaseRingSizeOfSubtower(unorderedTowers[1]);
    //     std::cout<<baseOfSubtower<<std::endl;
    //     std::cout<<baseOfSubtower2<<std::endl;
    //     std::cout<<unorderedTowers[1]<<std::endl;
    //     std::cout<<orderedTowers[0]<<std::endl;
    //     if (baseOfSubtower > 1 && _board.getTowerVector()[lowTower]->topRingSize() == baseOfSubtower + 1 && _board.getTowerVector()[tmpTower]->topRingSize() == 1)
    //     {
    //         if (pointedTower != tmpTower)
    //         {
    //             _board.setPointedTower(tmpTower);
    //             pointedTower = tmpTower;
    //         }
        
    //         if (baseOfSubtower % 2 == 0)
    //         {
    //             _board.moveRingTo(unorderedTowers[1]);
    //             _tmpBaseTower = unorderedTowers[1];  
    //         }
    //         else
    //         {
    //             _board.moveRingTo(orderedTowers[0]);
    //             _tmpBaseTower = orderedTowers[0];                          
    //         }
    //     }
    //     else if (!_board.getTowerVector()[unorderedTowers[1]]->isEmpty() && _board.getTowerVector()[tmpTower]->topRingSize() + 1 == _board.getTowerVector()[unorderedTowers[1]]->topRingSize())
    //     {
    //         if (pointedTower != tmpTower)
    //         {
    //             _board.setPointedTower(tmpTower);
    //             pointedTower = tmpTower;
    //         }
    //         _board.moveRingTo(unorderedTowers[1]);
    //         _tmpBaseTower = unorderedTowers[1];  
    //     }
    //     else if (baseOfSubtower2 + 1 == baseOfSubtower && baseOfSubtower2 != 0)
    //     {
    //         if (pointedTower != unorderedTowers[1])
    //         {
    //             _board.setPointedTower(unorderedTowers[1]);
    //             pointedTower = unorderedTowers[1];
    //         }

    //         if (baseOfSubtower2 % 2 == 1)
    //         {
    //             _board.moveRingTo(unorderedTowers[0]);
    //             _tmpBaseTower = unorderedTowers[0];  
    //         }
    //         else
    //         {
    //             _board.moveRingTo(orderedTowers[0]);
    //             _tmpBaseTower = orderedTowers[0];                          
    //         }
    //     }
    //     else
    //     {
    //         if (pointedTower != tmpTower)
    //         {
    //             _board.setPointedTower(tmpTower);
    //             pointedTower = tmpTower;
    //         }

    //         if (_board.getTowerVector()[tmpTower]->topRingSize() + 1 == _board.getTowerVector()[orderedTowers[0]]->topRingSize())
    //         {
    //             int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
    //             if (_board.getTowerVector()[destTower]->topRingSize() + 1 == _board.getTowerVector()[tmpTower]->topRingSize())
    //             {
    //                 if (pointedTower != destTower)
    //                 {
    //                     _board.setPointedTower(destTower);
    //                     pointedTower = destTower;
    //                 }
    //                 _board.moveRingTo(tmpTower);
    //                 _tmpBaseTower = tmpTower;
    //             }
    //             else
    //             {
    //                 _board.moveRingTo(orderedTowers[0]);
    //                 _tmpBaseTower = orderedTowers[0];
    //             }
    //         }
    //         else
    //         {
    //             _board.moveRingTo(unorderedTowers[0]);
    //             _tmpBaseTower = unorderedTowers[0];
    //         }       
    //     }
        
    // }
    // else if (orderedTowers.size() == 2)
    // {
    //     // orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), lowTower), orderedTowers.end());
    //     // orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), largeTower), orderedTowers.end());
    //     int baseOfSubtower = _board.getBaseRingSizeOfSubtower(unorderedTowers[0]);
    //     int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
    //     int startTower = _board.getTowerWithGreatestBaseRing();
    //     if (_board.getTowerVector()[destTower]->topRingSize() == _board.getTowerVector()[lowTower]->topRingSize() + 1  
    //         && startTower != destTower)
    //     {
    //         if (pointedTower != lowTower)
    //         {
    //             _board.setPointedTower(lowTower);
    //             pointedTower = lowTower;
    //         }
    //         _board.moveRingTo(destTower);
    //         _tmpBaseTower = destTower;  
    //     }
    //     else if (_board.getTowerVector()[destTower]->topRingSize() + 1 == _board.getTowerVector()[lowTower]->topRingSize() 
    //         && startTower != destTower)
    //     {
    //         if (pointedTower != lowTower)
    //         {
    //             _board.setPointedTower(lowTower);
    //             pointedTower = lowTower;
    //         }
    //         _board.moveRingTo(startTower);
    //         _tmpBaseTower = startTower;             
    //     }
    //     else if (baseOfSubtower > 0 && _board.getTowerVector()[destTower]->topRingSize() != _board.getTowerVector()[lowTower]->topRingSize() + 1)
    //     {
    //         if (pointedTower != lowTower)
    //         {
    //             _board.setPointedTower(lowTower);
    //             pointedTower = lowTower;
    //         }
    //         _board.moveRingTo(orderedTowers[0]);
    //         _tmpBaseTower = orderedTowers[0];
    //     }
    //     else if (baseOfSubtower > 0)
    //     {
    //         if (pointedTower != unorderedTowers[0])
    //         {
    //             _board.setPointedTower(unorderedTowers[0]);
    //             pointedTower = unorderedTowers[0];
    //         }

    //         if (_board.getTowerVector()[unorderedTowers[0]]->topRingSize() + 1 == _board.getTowerVector()[orderedTowers[0]]->topRingSize())
    //         {
    //             _board.moveRingTo(orderedTowers[0]);
    //             _tmpBaseTower = orderedTowers[0];
    //         }
    //         else if (_board.getTowerVector()[unorderedTowers[0]]->topRingSize() + 1 == _board.getTowerVector()[orderedTowers[1]]->topRingSize())
    //         {
    //             _board.moveRingTo(orderedTowers[1]);
    //             _tmpBaseTower = orderedTowers[1];
    //         }
    //     }
    //     else
    //     {
    //         if (pointedTower != startTower)
    //         {
    //             _board.setPointedTower(startTower);
    //             pointedTower = startTower;
    //         }
    //         _board.moveRingTo(unorderedTowers[0]);
    //         _tmpBaseTower = unorderedTowers[0];
    //     }

    // }
    // else if (orderedTowers.size() == 3) 
    // {
    //     if (pointedTower != lowTower)
    //     {
    //         _board.setPointedTower(lowTower);
    //         pointedTower = lowTower;
    //     }

    //     orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), lowTower), orderedTowers.end());
    //     orderedTowers.erase(std::remove(orderedTowers.begin(), orderedTowers.end(), largeTower), orderedTowers.end());
    //     if( _board.getTowerVector()[lowTower]->hasOneRing())
    //     {
    //         _board.moveRingTo(orderedTowers[0]);
    //         _tmpBaseTower = orderedTowers[0];
    //     }
    //     else
    //     {
    //         int destTower = _board.getTowerWithRingSize(_board.getTowerVector()[lowTower]->baseRingSize() + 1);
    //         if (_board.getTowerVector()[destTower]->hasOneRing())
    //         {
    //             if (_board.getTowerVector()[lowTower]->size() % 2 == 1)
    //             {
    //                 _board.moveRingTo(destTower);
    //                 _tmpBaseTower = destTower;  
    //             }
    //             else
    //             {
    //                 _board.moveRingTo(largeTower);
    //                 _tmpBaseTower = largeTower;                          
    //             }
    //         }
    //     }
        
    // }
    // else
    // {
    //     int startTower = _board.getTowerWithGreatestBaseRing();
    //     int baseOfSubtower = _board.getBaseRingSizeOfSubtower(startTower);
    // }
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};

void HanoiResolver::moveRing(Board& _board, int _sourceTower, int _destTower)
{
    setPointedTower(_board, _sourceTower);
    _board.moveRingTo(_destTower);
}
void HanoiResolver::setPointedTower(Board& _board, int _tower)
{
    int pointedTower = _board.getPointedTower();
    if (pointedTower != _tower)
    {
        _board.setPointedTower(_tower);
        pointedTower = _tower;
    }    
}
void HanoiResolver::loadTowerStatVector(Board& _board)
{
    if (!tower.empty())
        return;

    BoardState state = _board.getBoardState();
    for(BoardState::iterator itTower = state.begin(); itTower != state.end(); itTower++)
    {
        TowerStat towerStat;
        towerStat.size         = (*itTower).size();
        towerStat.isEmpty      = true;
        towerStat.hasAllRings  = (towerStat.size == _board.getNumberOfRings());
        towerStat.isStartTower = (itTower == state.begin());
        towerStat.isFinalTower = ((itTower - state.begin()) == _board.getFinalTower());
        towerStat.isOrdered    = true;
        for(std::vector<int>::iterator itRing = (*itTower).begin(); itRing != (*itTower).end(); itRing++)
        {
            towerStat.isEmpty     = false;
            towerStat.topRingSize = *itRing;
            if (towerStat.baseRingSize == 0 )
                towerStat.baseRingSize = *itRing;

            if (itRing != (*itTower).begin() && *(itRing - 1) != ((*itRing) + 1))
            {
                towerStat.isOrdered              = true;
                towerStat.baseRingSizeOfSubtower = *itRing;
            }                
        } 
        tower.push_back(towerStat);
    }     
}