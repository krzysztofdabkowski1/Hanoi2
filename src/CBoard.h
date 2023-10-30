#include "IAlgorithmResolver.h"
#include <map>
#include <string>

class Board
{
    public:
    Board(unsigned int numberOfTowers, 
          unsigned int numberOfRings,
          IAlgorithmResolver* resolver,
          unsigned int finalTower = 3);
    ~Board();
    void setTowers(unsigned int numerOfTowers, 
                   unsigned int numberOfRings);
    void printBoard();
    void movePointerToRight();
    void movePointerToLeft();
    MessageCode pickRing();
    MessageCode putRing();
    bool isGameOver();
    inline int getMoveCounter() {return _movesCounter;};
    inline int getFinalTower() {return _finalTower;};

    private:
    IAlgorithmResolver* _resolver = nullptr;
    TowerVector _towerVector;
    int _pointedTower;
    CRing* _pickedRing;
    int _numberOfRings;
    int _movesCounter;
    int _finalTower;

    inline bool isRingPicked() {return (_pickedRing == nullptr ? false: true);};
    inline bool isFirstTowerEmpty() {return _towerVector[0]->isEmpty();}
    bool hasAllRings(unsigned _tower);
};