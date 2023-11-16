#ifndef IAlgorithmResolver_H
#define IAlgorithmResolver_H

#include <vector>
#include "CBoard.h"

class IAlgorithmResolver
{
    /* Do one move according to the implementation of algorithm*/
    virtual void MakeNextStep(Board& _board) ;

    /* Resolves entire game and returns number of steps*/
    virtual unsigned int ResolveGame(Board& _board) ;
};

#endif