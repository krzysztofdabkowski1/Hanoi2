#ifndef CTower_H
#define CTower_H

#include <vector>
#include "CRing.h"

typedef std::vector<CRing*>  RingVector;

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
    CRing * ptrTopRing;
    RingVector _ringVector;
    unsigned int _number;

    void addRing(CRing *ring, MessageCode& code);
    void addRing(CRing *ring);
    CRing* popRing(MessageCode& code);
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};
#endif