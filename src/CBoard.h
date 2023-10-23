#include "IAlgorithmResolver.h"

class Board
{
    public:
    Board(unsigned int numberOfTowers, 
          unsigned int numberOfRings, 
          IAlgorithmResolver* resolver);
    ~Board();
    void setTowers(unsigned int numerOfTowers, 
                   unsigned int numberOfRings);
    void printBoard();
    void movePointerToRight();
    void movePointerToLeft();
    void pickRing();
    void putRing();
    bool isGameOver();

    private:
    IAlgorithmResolver* _resolver = nullptr;
    TowerVector _towerVector;
    int _pointedTower;
    CRing* _pickedRing;
    int _numberOfRings;
    int _moveCounter;
    inline bool isRingPicked() {return (_pickedRing == nullptr ? false: true);};
    inline bool isFirstTowerEmpty() {return _towerVector[0]->isEmpty();}
    bool hasAllRings(unsigned _tower);
};