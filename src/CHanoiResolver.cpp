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
                 tower[THIRD].baseRingSize + 1 == tower[SECOND].topRingSize && 
                 tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1)
            moveRing(_board, THIRD, (tower[THIRD].size % 2 == 0) ? FIRST : SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize == tower[THIRD].baseRingSize + 1 && 
                 tower[FIRST].topRingSize == tower[SECOND].baseRingSize + 1)
            moveRing(_board, THIRD, (tower[THIRD].size % 2 == 0) ? FIRST : SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);        
        else if (tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if (tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[THIRD].topRingSize + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, SECOND);
        else if (tower[SECOND].isOrdered &&
                 tower[THIRD].isEmpty &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                 tower[SECOND].baseRingSize + 1 != tower[THIRD].baseRingSize)
            moveRing(_board, FIRST, SECOND);   
        else if (tower[SECOND].isOrdered &&
                 tower[THIRD].size == 1 &&
                 tower[THIRD].topRingSize + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, SECOND);    
        else if (tower[THIRD].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].size < 3 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, THIRD);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].size == 2 &&
                 tower[THIRD].isOrdered &&
                 tower[THIRD].baseRingSize + 1 == tower[SECOND].baseRingSize)
            moveRing(_board, THIRD, (tower[THIRD].size % 2 == 0) ? FIRST : SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].size == 2 &&
                 tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize)
            moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);
        else if (tower[SECOND].isOrdered &&
                 tower[SECOND].size > 1 &&
                 tower[FIRST].sizeOfSubtower < 2 &&
                 tower[THIRD].topRingSize + 1 == tower[FIRST].topRingSize &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, FIRST);
        else if (tower[SECOND].isOrdered &&
                 tower[SECOND].size > 1 &&
                 //tower[SECOND].size <= 3 &&
                 tower[FIRST].sizeOfSubtower < 2 &&
                 tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize)
            moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);
        else if (tower[SECOND].isOrdered &&
                 tower[THIRD].size > 1 &&
                 tower[SECOND].size == 1 &&
                 tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 1) ? FIRST : SECOND);
        else if (tower[SECOND].isEmpty &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].baseRingSizeOfSubtower > 0 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? SECOND : THIRD);
        else if (tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[THIRD].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].topRingSize == 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize)
            moveRing(_board, FIRST, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].topRingSize + 1 == tower[FIRST].topRingSize && 
                 tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
             moveRing(_board, THIRD, FIRST);            
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[SECOND].topRingSize + 1 == tower[FIRST].topRingSize)
            moveRing(_board, SECOND, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize + 1 == tower[FIRST].topRingSize &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, SECOND, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].size > 1 &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
             moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? SECOND : THIRD);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].size == 1 &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize  &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? SECOND : THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].baseRingSizeOfSubtower == tower[FIRST].topRingSize + 1 &&
                 tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].isEmpty &&
                 !tower[THIRD].isOrdered &&
                 tower[THIRD].baseRingSizeOfSubtower + 1 == tower[FIRST].topRingSize)
            moveRing(_board, FIRST, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].size == 1 &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                 tower[THIRD].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].size == 1 &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, THIRD, SECOND);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[FIRST].topRingSize  == tower[THIRD].baseRingSize + 1)
            moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);
        else if (tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                 tower[FIRST].topRingSize  == tower[THIRD].baseRingSize + 1)
            moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].size == 1 &&
                 !tower[THIRD].isOrdered &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize && 
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, THIRD, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].size == 1 &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if (tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size > 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].baseRingSizeOfSubtower &&
                 tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, SECOND, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                 tower[SECOND].baseRingSizeOfSubtower + 1 == tower[FIRST].topRingSizeOfBaseTower &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, THIRD, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].size == 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].baseRingSizeOfSubtower + 1)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[SECOND].topRingSize + 1== tower[FIRST].topRingSizeOfBaseTower)
            moveRing(_board, FIRST, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSize + 1 == tower[FIRST].topRingSize &&
                 tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].topRingSizeOfBaseTower + 1)
            moveRing(_board, FIRST, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].size == 1 &&
                 tower[FIRST].topRingSize  == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1 )
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size == 1 &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize )
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size > 1 &&
                 tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                 tower[SECOND].topRingSize == tower[THIRD].baseRingSize + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower )
            moveRing(_board, THIRD, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size == 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].topRingSize + 1)
            moveRing(_board, THIRD, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isEmpty &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].baseRingSizeOfSubtower + 1)
            moveRing(_board, FIRST, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isEmpty &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower)
            moveRing(_board, FIRST, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].size == 1 &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSizeOfBaseTower + 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].topRingSizeOfBaseTower + 1)
            moveRing(_board, THIRD, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size == 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1)
            moveRing(_board, SECOND, THIRD);        
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].size > 1 &&
                 tower[THIRD].size > 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                 tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSize )
            moveRing(_board, FIRST, SECOND);  
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size > 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                 tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower && 
                 tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].baseRingSize + 1)
            moveRing(_board, FIRST, THIRD);  
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].size > 1 &&
                 tower[THIRD].size > 1 &&
                 tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSize == tower[THIRD].baseRingSize + 1 &&
                 tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].baseRingSize + 1)
            moveRing(_board, THIRD, SECOND);
        else if (!tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower == 1 &&
                 tower[SECOND].sizeOfSubtower == 1 &&
                 tower[THIRD].size > 1 &&
                 tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                 tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].baseRingSize + 1)
            moveRing(_board, FIRST, SECOND);
        else if (tower[FIRST].isOrdered &&
                 !tower[SECOND].isOrdered &&
                 tower[THIRD].isOrdered &&
                 tower[FIRST].size == 1 &&
                 tower[SECOND].sizeOfSubtower > 1 &&
                 tower[THIRD].size > 1 &&
                 tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                 tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].baseRingSize + 1)
            moveRing(_board, THIRD, FIRST);
        else if (!tower[FIRST].isOrdered &&
                 tower[SECOND].isOrdered &&
                 !tower[THIRD].isOrdered &&
                 tower[FIRST].sizeOfSubtower > 1 &&
                 tower[SECOND].size > 1 &&
                 tower[THIRD].sizeOfSubtower == 1 &&
                 tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                 tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                 tower[SECOND].topRingSize == tower[THIRD].topRingSizeOfBaseTower + 1)
            moveRing(_board, THIRD, FIRST);
        else
        {
            std::cout<<" "<<tower[FIRST].baseRingSizeOfSubtower<<" "<<tower[SECOND].topRingSizeOfBaseTower<<" "<<tower[THIRD].baseRingSizeOfSubtower<<" "<<std::endl;
            int sourceTower, destTower;
            findSourceDestTower(sourceTower, destTower);
            if (sourceTower == THIRD)
            {
                if (tower[SECOND].topRingSize != tower[SECOND].baseRingSize &&
                    tower[FIRST].topRingSize  != tower[FIRST].baseRingSize  &&
                    tower[SECOND].topRingSize + 1 == tower[FIRST].topRingSize)
                    moveRing(_board, SECOND, FIRST);
                else if (tower[SECOND].topRingSize != tower[SECOND].baseRingSize &&
                    tower[FIRST].topRingSize  != tower[FIRST].baseRingSize  &&
                    tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize)
                    moveRing(_board, FIRST, SECOND);
                else
                    moveRing(_board, THIRD, (tower[THIRD].size % 2 == 0) ? FIRST : SECOND);
            }
            else if (sourceTower == FIRST && destTower == SECOND)
            {
                moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 1) ? SECOND : THIRD);
            }
            else if (sourceTower == SECOND && destTower == FIRST)
            {
                moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);
            }
            else if (sourceTower == SECOND && destTower == THIRD)
            {
                moveRing(_board, SECOND, THIRD);
            }
            else if (sourceTower == FIRST && destTower == THIRD)
            {
                moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? SECOND : THIRD);
            }
        }
    }
    else if (tower[THIRD].baseRingSize == _board.getNumberOfRings())
    {
        if     (tower[FIRST].isEmpty &&
                tower[SECOND].isOrdered &&
                tower[THIRD].isOrdered &&
                tower[SECOND].size > 1 &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize)
            moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);   
        else if(tower[FIRST].isEmpty &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[SECOND].size > 1 &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, (tower[SECOND].size % 2 == 0) ? FIRST : THIRD);  
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].size > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, FIRST); 
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].size == 1 &&
                tower[FIRST].baseRingSize + 1 == tower[SECOND].topRingSize &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize)
            moveRing(_board, SECOND, THIRD);
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].size > 1 &&
                tower[FIRST].baseRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, FIRST, (tower[FIRST].size % 2 == 0) ? SECOND : THIRD);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1)
            moveRing(_board, FIRST, THIRD);
        else if(tower[FIRST].isEmpty &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, SECOND, THIRD);
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 0) ? SECOND : FIRST); 
        else if(!tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 0) ? SECOND : FIRST); 
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1 &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, SECOND); 
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, THIRD, FIRST);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].size == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].baseRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, (tower[SECOND].sizeOfSubtower % 2 == 0) ? THIRD : FIRST);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[FIRST].baseRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, SECOND, FIRST);    
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[FIRST].baseRingSize + 1 == tower[SECOND].topRingSize &&
                tower[SECOND].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, FIRST);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[FIRST].baseRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1)
            moveRing(_board, FIRST, THIRD);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[FIRST].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSizeOfBaseTower + 1)
            moveRing(_board, SECOND, THIRD);
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSizeOfBaseTower + 1 &&
                tower[FIRST].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, FIRST, SECOND);
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].baseRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSizeOfBaseTower + 1 &&
                tower[FIRST].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, FIRST, SECOND);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSizeOfBaseTower + 1 &&
                tower[SECOND].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 0) ? FIRST : SECOND);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].topRingSize + 1 &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSizeOfBaseTower + 1)
            moveRing(_board, THIRD, SECOND);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1)
            moveRing(_board, FIRST, SECOND);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].topRingSize + 1)
            moveRing(_board, FIRST, THIRD);
        else if(tower[FIRST].isEmpty &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, SECOND, (tower[SECOND].sizeOfSubtower % 2 == 0) ? FIRST : THIRD);
        else if(tower[FIRST].isEmpty &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, (tower[SECOND].sizeOfSubtower % 2 == 0) ? FIRST : THIRD);
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, FIRST); 
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].baseRingSize + 1 == tower[SECOND].topRingSize &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, SECOND, THIRD); 
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].size > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].baseRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, FIRST, (tower[FIRST].size % 2 == 0) ? SECOND : THIRD); 
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[SECOND].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, FIRST, THIRD); 
        else if(tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].size == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 0) ? SECOND : FIRST); 
        else if(!tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].size == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 0) ? SECOND : FIRST); 
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSizeOfBaseTower == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, FIRST, SECOND); 
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, FIRST); 
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize  == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize  &&
                tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, THIRD); 
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower  &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, SECOND, FIRST);
        else if(!tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower > 1 &&
                tower[SECOND].size == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSize)
            moveRing(_board, THIRD, FIRST);
        else if(!tower[FIRST].isOrdered &&
                tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower > 1 &&
                tower[SECOND].size == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower  == tower[THIRD].baseRingSizeOfSubtower + 1)
            moveRing(_board, THIRD, SECOND);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? THIRD : SECOND);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].topRingSize + 1 &&
                tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? THIRD : SECOND);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, SECOND, THIRD);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, FIRST, SECOND);    
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower > 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSizeOfBaseTower + 1 &&
                tower[SECOND].topRingSize == tower[THIRD].baseRingSizeOfSubtower + 1 &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, (tower[THIRD].sizeOfSubtower % 2 == 0) ? FIRST : SECOND);  
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSizeOfBaseTower)
            moveRing(_board, THIRD, SECOND);       
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, FIRST, SECOND); 
        else if(tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].size > 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                tower[FIRST].baseRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, SECOND, FIRST);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower == 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSize == tower[THIRD].topRingSize + 1 &&
                tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].baseRingSizeOfSubtower + 1)
            moveRing(_board, THIRD, FIRST);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower > 1 &&
                tower[SECOND].sizeOfSubtower > 1 &&
                tower[THIRD].size == 1 &&
                tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].baseRingSizeOfSubtower + 1 &&
                tower[SECOND].topRingSizeOfBaseTower + 1 == tower[THIRD].topRingSize)
            moveRing(_board, SECOND, THIRD);
        else if(!tower[FIRST].isOrdered &&
                !tower[SECOND].isOrdered &&
                !tower[THIRD].isOrdered &&
                tower[FIRST].sizeOfSubtower > 1 &&
                tower[SECOND].sizeOfSubtower == 1 &&
                tower[THIRD].sizeOfSubtower == 1 &&
                tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize &&
                tower[FIRST].topRingSizeOfBaseTower == tower[SECOND].topRingSize + 1 &&
                tower[SECOND].topRingSize == tower[THIRD].topRingSize + 1)
            moveRing(_board, FIRST, (tower[FIRST].sizeOfSubtower % 2 == 0) ? SECOND : THIRD);
    }


    tower.clear();
};

unsigned int HanoiResolver::ResolveGame(Board& _board) 
{
    return 0;
};

void HanoiResolver::moveRing(Board& _board, int _sourceTower, int _destTower)
{
    std::cout<<"kurka:"<<_sourceTower<<" rurka:"<<_destTower<<std::endl;
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
        towerStat.size           = (*itTower).size();
        towerStat.isEmpty        = true;
        towerStat.hasAllRings    = (towerStat.size == _board.getNumberOfRings());
        towerStat.isStartTower   = (itTower == state.begin());
        towerStat.isFinalTower   = ((itTower - state.begin()) == _board.getFinalTower());
        towerStat.isOrdered      = true;
        towerStat.sizeOfSubtower = 0;
        for(std::vector<int>::iterator itRing = (*itTower).begin(); itRing != (*itTower).end(); itRing++)
        {
            towerStat.isEmpty     = false;
            towerStat.topRingSize = *itRing;
            if (towerStat.baseRingSize == 0 )
                towerStat.baseRingSize = *itRing;

            if (towerStat.baseRingSizeOfSubtower > 0)
                towerStat.sizeOfSubtower++;

            if (itRing != (*itTower).begin() && *(itRing - 1) != ((*itRing) + 1))
            {
                towerStat.isOrdered              = false;
                towerStat.baseRingSizeOfSubtower = *itRing;
                towerStat.topRingSizeOfBaseTower = *(itRing - 1);
                towerStat.sizeOfSubtower         = 1;
            }                
        } 
        tower.push_back(towerStat);
    }     
}

void HanoiResolver::findSourceDestTower(int& _sourceTower, int& _destTower)
{
    if (tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize && tower[THIRD].size == 1)
    {
        _sourceTower = SECOND;
        _destTower   = THIRD;
    }
    else if (tower[SECOND].baseRingSize + 1 == tower[THIRD].baseRingSize && 
             tower[FIRST].baseRingSizeOfSubtower + 1 == tower[THIRD].topRingSize)
    {
        _sourceTower = FIRST;
        _destTower   = THIRD;
    }
    else if (tower[THIRD].baseRingSize + 1 == tower[SECOND].baseRingSize &&
             tower[THIRD].size > 1)
    {
        _sourceTower = THIRD;
        _destTower   = SECOND;       
    }
    else if (tower[THIRD].baseRingSize + 1 == tower[SECOND].baseRingSize && 
             tower[THIRD].size == 1 &&
             tower[SECOND].size > 1)
    {
        if (tower[FIRST].baseRingSizeOfSubtower == tower[SECOND].baseRingSizeOfSubtower + 1)
        {
            _sourceTower = SECOND;
            _destTower   = FIRST;             
        }
        else if (tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize)
        {
            _sourceTower = FIRST;
            _destTower   = SECOND;  
        }     
    }
    else if ((tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSize && tower[SECOND].isOrdered) || 
             (tower[SECOND].topRingSize + 1 == tower[FIRST].topRingSize && tower[FIRST].baseRingSizeOfSubtower + 1 == tower[SECOND].topRingSizeOfBaseTower))
    {
        _sourceTower = FIRST;
        _destTower   = SECOND; 
    }
    else if (tower[FIRST].baseRingSizeOfSubtower == tower[SECOND].topRingSizeOfBaseTower + 1 && 
             tower[THIRD].isOrdered && 
             tower[THIRD].topRingSize == tower[SECOND].topRingSize + 1)
    {
        _sourceTower = SECOND;
        _destTower   = THIRD; 
    }
    else if (tower[FIRST].topRingSize + 1 == tower[SECOND].topRingSizeOfBaseTower && 
             tower[THIRD].isOrdered && 
             tower[THIRD].topRingSize == tower[SECOND].topRingSize + 1)
    {
        _sourceTower = SECOND;
        _destTower   = THIRD; 
    }

    std::cout<<_sourceTower<<std::endl;
    std::cout<<_destTower<<std::endl;
    if (tower[_sourceTower].baseRingSize > tower[FIRST].baseRingSize)
    {
        _sourceTower = FIRST;
        _destTower   = THIRD;               
    }
}