#include "CTower.h"
#include <iostream>

Tower::Tower(unsigned int number)
{
    _number = number;
    ptrTopRing = nullptr;
};
Tower::~Tower()
{
    std::cout<<"Deleting tower:"<<_number<<std::endl;
    for(RingVector::iterator itr = _ringVector.begin(); itr != _ringVector.end(); itr++)
    {
        delete *itr;
    }
};

void Tower::addRing(Ring *ring, MessageCode& _code)
{
    if(_ringVector.empty())
    {
        _ringVector.push_back(ring);
        ptrTopRing = ring;
        _code = MessageCode::NO_MESSAGE;
    }     
    else
    {
        if(ptrTopRing->isGreaterThan(ring))
        {
            _code = MessageCode::TOO_LARGE;

        }
        else
        {
            _ringVector.push_back(ring);
            ptrTopRing = ring;
            _code = MessageCode::NO_MESSAGE;
        }  
    }
    
    // std::cout<<"T"<<_number<<" dodaje: rozmiar: " << ptrTopRing->getSize()<<std::endl;
};
void Tower::addRing(Ring *ring)
{
    MessageCode code;
    this->addRing(ring, code);
}
Ring* Tower::popRing(MessageCode& _code)
{
    // printTower();
    if(_ringVector.empty())
    {
        _code = MessageCode::EMPTY_TOWER;
        return nullptr;
    }     
    
    Ring* tmpRing;
    tmpRing = *(--_ringVector.end());
    _ringVector.erase(--_ringVector.end());  
    if(_ringVector.end() != _ringVector.begin())
        ptrTopRing = *(--_ringVector.end());
    else 
        ptrTopRing = nullptr;

    _code = MessageCode::NO_MESSAGE;
    return tmpRing;
};

void Tower::printTower()
{
    std::cout<<"[T"<<_number<<"]: "<<std::endl;
    for(RingVector::iterator itr = _ringVector.begin(); itr != _ringVector.end(); itr++)
    {
        std::cout<<(*itr)->getSize();
    }
    std::cout<<std::endl;
};

bool Tower::hasRingWithSize(unsigned size)
{
    bool ret = false;
    for (RingVecIt it = _ringVector.begin(); it != _ringVector.end(); it++)
    {
        if ((*it)->getSize() == size)
        {
            ret = true;
            break;
        }
    }
    return ret;
};
bool Tower::hasOrderedRings()
{
    bool ret = true;
    if (_ringVector.size() > 1)
        for (RingVecIt it = _ringVector.begin() + 1; it != _ringVector.end(); it++)
        {
            if ((*it)->getSize() + 1 != (*(it - 1))->getSize())
            {
                ret = false;
                break;
            }
        }
    else if(_ringVector.size() == 1)
        ret = true;
    else    
        ret = false;
    return ret;
}
int Tower::getBaseRingSizeOfSubtower()
{
    int ret = 0;
    int endOfSubtower = 0;
    RingVecIt it;
    if(_ringVector.size() > 1)
    {
        for (it = _ringVector.begin() + 1; it != _ringVector.end(); it++)
        {
            if ((*it)->getSize() + 1 != (*(it - 1))->getSize())
            {
                endOfSubtower++;
                if (endOfSubtower == 1)
                    ret = (*it)->getSize(); 
            }
        }

        if (endOfSubtower > 1)
            ret = 0;
    }

    return ret;    
}

TowerState Tower::getTowerState()
{
    TowerState state;
    for (RingVecIt it = _ringVector.begin(); it != _ringVector.end(); it++)
        state.push_back((*it)->getSize());
  
    return state;
}