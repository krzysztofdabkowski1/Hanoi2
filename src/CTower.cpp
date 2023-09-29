#include "CTower.h"
#include <iostream>

CTower::CTower(unsigned int number)
{
    _number = number;
    ptrTopRing = nullptr;
};

void CTower::addRing(CRing *ring)
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

CRing* CTower::popRing()
{
    printTower();

    if(_ringSet.empty())
    {
        throw EmptyTowerException();
    }     
    
    CRing* tmpRing;
    tmpRing = *(--_ringSet.end());
    _ringSet.erase(--_ringSet.end());  
    if(_ringSet.end() != _ringSet.begin())
        ptrTopRing = *(--_ringSet.end());
    else 
        ptrTopRing = nullptr;

    std::cout<<"T"<<_number<<" usuwam: rozmiar: " << tmpRing->getSize()<<std::endl;
    return tmpRing;
};

void CTower::printTower()
{
    std::cout<<"[T"<<_number<<"]: "<<std::endl;
    for(RingSet::iterator itr = _ringSet.begin(); itr != _ringSet.end(); itr++)
    {
        std::cout<<(*itr)->getSize();
    }
    std::cout<<std::endl;
}