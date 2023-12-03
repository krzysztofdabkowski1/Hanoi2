#ifndef Tower_H
#define Tower_H

#include <vector>
#include "CRing.h"

typedef std::vector<Ring*>  RingVector;
typedef std::vector<Ring*>::iterator RingVecIt;

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
    inline bool hasOneRing(){return _ringVector.size() == 1;};
    inline int baseRingSize(){return _ringVector[0]->getSize();};
    inline int topRingSize(){return _ringVector[_ringVector.size() - 1]->getSize();};    
    inline int size(){return _ringVector.size();};    
    void printTower();
    bool hasRingWithSize(unsigned size);
    bool hasOrderedRings();
   private:
      
};
#endif