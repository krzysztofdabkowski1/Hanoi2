#include <set>
#include "Ring.h"
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

typedef std::set<Ring*> RingSet;

class Tower
{
  public:
    Tower(unsigned int number);
    mutable Ring * ptrTopRing;
    mutable RingSet _ringSet;
    unsigned int _number;

    void addRing(Ring *ring) const;
    Ring* popRing();
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};