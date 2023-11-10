#include "IAlgorithmResolver.h"
#include <iostream>

class HanoiResolver: public IAlgorithmResolver
{
    private:
    int _numberOfTowers;
    public:

    void MakeNextStep(Board& _board);

    unsigned int ResolveGame(Board& _board);
};