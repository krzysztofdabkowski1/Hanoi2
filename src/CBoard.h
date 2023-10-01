#include "IAlgorithmResolver.h"
enum Move
{
    left,
    right
};

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
    void movePointer(Move move);
    void pickRing();
    void putRing();

    private:
    IAlgorithmResolver* _resolver = nullptr;
    TowerVector _towerVector;
};