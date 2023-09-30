#include "IAlgorithmResolver.h"
#include <iostream>

class HanoiResolver: public IAlgorithmResolver
{
    void MakeNextStep(TowerVector& _towerVector);

    unsigned int ResolveGame(TowerVector& _towerVector);
};