#include <vector>
#include "CRing.h"
#include <exception>

struct GreaterRingException : public std::exception {
   const char * what () const throw () {
      return "The ring is too large!";
   }
};

struct EmptyTowerException : public std::exception {
   const char * what () const throw () {
      return "There are no rings!";
   }
};

typedef std::vector<CRing*> RingVector;

class CTower
{
  public:
    CTower(unsigned int number);
    ~CTower();
    CRing * ptrTopRing;
    RingVector _ringVector;
    unsigned int _number;

    void addRing(CRing *ring);
    CRing* popRing();
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};