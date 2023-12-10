#include "IAlgorithmResolver.h"
#include <iostream>

struct TowerStat
{
    int  size;
    int  baseRingSize;
    int  topRingSize;
    int  baseRingSizeOfSubtower;
    bool isEmpty;
    bool hasAllRings;
    bool isOrdered;
    bool isStartTower;
    bool isFinalTower;
    TowerStat():
        size(0),
        baseRingSize(0),
        topRingSize(0),
        baseRingSizeOfSubtower(0),
        isEmpty(true),
        hasAllRings(false),
        isOrdered(false),
        isStartTower(false),
        isFinalTower(false)
        {};
};

typedef std::vector<TowerStat> TowerStatVector;

class HanoiResolver: public IAlgorithmResolver
{
    private:
    int numberOfTowers;
    int tmpBaseTower;
    TowerStatVector tower;

    void setPointedTower(Board& _board, int _tower);
    void loadTowerStatVector(Board& _board);
    void moveRing(Board& _board, int _sourceTower, int _destTower);
    public:

    void MakeNextStep(Board& _board);

    unsigned int ResolveGame(Board& _board);
};