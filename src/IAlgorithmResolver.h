
#include <vector>
#include "CBoard.h"

typedef std::vector<CTower*> TowerVector;

class IAlgorithmResolver
{
    /* Do one move according to the implementation of algorithm*/
    virtual void MakeNextStep(TowerVector& _towerVector) = 0;

    /* Resolves entire game and returns number of steps*/
    virtual unsigned int ResolveGame(TowerVector& _towerVector) = 0;
};
