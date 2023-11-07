#ifndef CTower_H
#define CTower_H

#include <vector>
#include "CRing.h"

typedef std::vector<Ring*>  RingVector;

enum MessageCode
{
    NO_MESSAGE,
    EMPTY_TOWER,
    TOO_LARGE   
};

class CTower
{
  public:
    CTower(unsigned int number);
    ~CTower();
    Ring * ptrTopRing;
    RingVector _ringVector;
    unsigned int _number;

    void addRing(Ring *ring, MessageCode& code);
    void addRing(Ring *ring);
    Ring* popRing(MessageCode& code);
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};
#endif