#pragma once
#include <set>
#include "CTower.h"

typedef std::set<CTower*> TowerSet;

class IAlgorithmResolver
{
    /* Do one move according to the implementation of algorithm*/
    virtual void MakeNextStep(TowerSet& _towerSet) = 0;

    /* Resolves entire game and returns number of steps*/
    virtual unsigned int ResolveGame(TowerSet& _towerSet) = 0;
};