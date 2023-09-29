#include <set>
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

typedef std::set<CRing*> RingSet;

class CTower
{
  public:
    CTower(unsigned int number);
    CRing * ptrTopRing;
    RingSet _ringSet;
    unsigned int _number;

    void addRing(CRing *ring);
    CRing* popRing();
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};