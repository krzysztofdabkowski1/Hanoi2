#ifndef Board_H
#define Board_H

#include <map>
#include <string>
#include "CTower.h"

typedef std::vector<Tower*> TowerVector;
typedef std::vector<Tower*>::iterator TowerVecIt;

class Board
{
    public:
    Board(unsigned int numberOfTowers, 
          unsigned int numberOfRings,
          unsigned int finalTower = 3);
    ~Board();
    void setTowers(unsigned int numerOfTowers, 
                   unsigned int numberOfRings);
    void printBoard();
    void movePointerToRight();
    void movePointerToLeft();
    void moveRingTo(int destinationTower);
    MessageCode pickRing();
    MessageCode putRing();
    bool isGameOver();
    inline int getMoveCounter() {return _movesCounter;};
    inline int getFinalTower() {return _finalTower;};
    inline TowerVector getTowerVector() {return _towerVector;};
    inline int getPointedTower() {return _pointedTower;};
    inline void setPointedTower(int pointedTower) {_pointedTower = pointedTower;};
    bool hasTwoOrderedTowers(std::vector<int>& unorderedTower);
    void getOrderedTowers(std::vector<int>& orderedTower, std::vector<int>& unorderedTower);
    void getTowersSortedByBaseRing(std::vector<int>& towers);
    int getTowerWithLowestBaseRing();
    int getTowerWithGreatestBaseRing();


    private:
    TowerVector _towerVector;
    int _pointedTower;
    Ring* _pickedRing;
    int _numberOfRings;
    int _movesCounter;
    int _finalTower;

    inline bool isRingPicked() {return (_pickedRing == nullptr ? false: true);};
    inline bool isFirstTowerEmpty() {return _towerVector[0]->isEmpty();};
    bool hasAllRings(unsigned _tower);
    int towerWithLargestRing();
};
#endif