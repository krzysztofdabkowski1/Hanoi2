#include "IAlgorithmResolver.h"
#include <iostream>

class HanoiResolver: public IAlgorithmResolver
{
    private:
    int _numberOfTowers;
    public:

    void MakeNextStep(TowerVector& _towerVector);

    unsigned int ResolveGame(TowerVector& _towerVector);
};