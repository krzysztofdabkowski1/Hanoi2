#include "tower.h"
#include <iostream>

Tower::Tower(unsigned int number)
{
    _number = number;
    ptrTopRing = nullptr;
};

void Tower::addRing(Ring *ring) const
{
    if(_ringSet.empty())
    {
        _ringSet.insert(ring);
        ptrTopRing = ring;
    }     
    else
    {
        if(ptrTopRing->isGreaterThan(*ring))
            throw GreaterRingException();

        _ringSet.insert(ring);
        ptrTopRing = ring;
    }
    
    std::cout<<"T"<<_number<<" dodaje: rozmiar: " << ptrTopRing->getSize()<<std::endl;
};

Ring* Tower::popRing()
{
    printTower();

    if(_ringSet.empty())
    {
        throw EmptyTowerException();
    }     
    
    Ring* tmpRing;
    tmpRing = *(--_ringSet.end());
    _ringSet.erase(--_ringSet.end());  
    if(_ringSet.end() != _ringSet.begin())
        ptrTopRing = *(--_ringSet.end());
    else 
        ptrTopRing = nullptr;

    std::cout<<"T"<<_number<<" usuwam: rozmiar: " << tmpRing->getSize()<<std::endl;
    return tmpRing;
};

void Tower::printTower()
{
    std::cout<<"[T"<<_number<<"]: "<<std::endl;
    for(RingSet::iterator itr = _ringSet.begin(); itr != _ringSet.end(); itr++)
    {
        std::cout<<(*itr)->getSize();
    }
    std::cout<<std::endl;
}