#include "IAlgorithmResolver.h"
#include <iostream>

class HanoiResolver: public IAlgorithmResolver
{
    void MakeNextStep(TowerSet& _towerSet);

    unsigned int ResolveGame(TowerSet& _towerSet);
};