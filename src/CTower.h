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

enum MessageCode
{
    NO_MESSAGE,
    EMPTY_TOWER,
    TOO_LARGE   
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

    void addRing(CRing *ring, MessageCode& code);
    void addRing(CRing *ring);
    CRing* popRing(MessageCode& code);
    inline bool isEmpty(){return ptrTopRing == nullptr;};
    void printTower();
   private:
      
};