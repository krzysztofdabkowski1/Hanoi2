#include <vector>
#include "CRing.h"
#include <exception>

struct GreaterRingException : public std::exception {
   const char * what () const throw () {
      return "Wybrany krążek jest za duży!";
   }
};

struct EmptyTowerException : public std::exception {
   const char * what () const throw () {
      return "Brak krążków do wybrania!";
   }
};

typedef std::vector<CRing*> RingVector;

class CTower
{
  public:
    CTower(unsigned int number);
    CRing * ptrTopRing;
    RingVector _ringVector;
    unsigned int _number;

    void addRing(CRing *ring);
    CRing* popRing();
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};