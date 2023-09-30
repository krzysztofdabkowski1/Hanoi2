#include "CTower.h"
#include <iostream>

CTower::CTower(unsigned int number)
{
    _number = number;
    ptrTopRing = nullptr;
};

void CTower::addRing(CRing *ring)
{
    if(_ringVector.empty())
    {
        _ringVector.push_back(ring);
        ptrTopRing = ring;
    }     
    else
    {
        if(ptrTopRing->isGreaterThan(*ring))
            throw GreaterRingException();

        _ringVector.push_back(ring);
        ptrTopRing = ring;
    }
    
    std::cout<<"T"<<_number<<" dodaje: rozmiar: " << ptrTopRing->getSize()<<std::endl;
};

CRing* CTower::popRing()
{
    printTower();

    if(_ringVector.empty())
    {
        throw EmptyTowerException();
    }     
    
    CRing* tmpRing;
    tmpRing = *(--_ringVector.end());
    _ringVector.erase(--_ringVector.end());  
    if(_ringVector.end() != _ringVector.begin())
        ptrTopRing = *(--_ringVector.end());
    else 
        ptrTopRing = nullptr;

    std::cout<<"T"<<_number<<" usuwam: rozmiar: " << tmpRing->getSize()<<std::endl;
    return tmpRing;
};

void CTower::printTower()
{
    std::cout<<"[T"<<_number<<"]: "<<std::endl;
    for(RingVector::iterator itr = _ringVector.begin(); itr != _ringVector.end(); itr++)
    {
        std::cout<<(*itr)->getSize();
    }
    std::cout<<std::endl;
}