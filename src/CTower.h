#ifndef Tower_H
#define Tower_H

#include <vector>
#include "CRing.h"

class Tower;
typedef std::vector<Ring*>  RingVector;
typedef std::vector<Tower*> TowerVector;

enum MessageCode
{
    NO_MESSAGE,
    EMPTY_TOWER,
    TOO_LARGE   
};

class Tower
{
  public:
    Tower(unsigned int number);
    ~Tower();
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