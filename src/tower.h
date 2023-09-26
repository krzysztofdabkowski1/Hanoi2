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

class Tower
{
  public:
    Tower(unsigned int number);
    mutable CRing * ptrTopRing;
    mutable RingSet _ringSet;
    unsigned int _number;

    void addRing(CRing *ring) const;
    CRing* popRing();
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};