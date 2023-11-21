#include "IAlgorithmResolver.h"
#include <iostream>

class HanoiResolver: public IAlgorithmResolver
{
    private:
    int _numberOfTowers;
    int _tmpBaseTower;
    public:

    void MakeNextStep(Board& _board);

    unsigned int ResolveGame(Board& _board);
};