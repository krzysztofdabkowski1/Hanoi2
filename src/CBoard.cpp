#include "CBoard.h"
#include <iostream>
#include "windows.h" 
#include <math.h> 

Board::Board(unsigned int numberOfTowers, 
             unsigned int numberOfRings, 
             IAlgorithmResolver* resolver,
             unsigned int finalTower):
_resolver(resolver),
_numberOfRings(numberOfRings),
_pointedTower(0),
_movesCounter(0),
_finalTower(finalTower),
_pickedRing(nullptr)
{
    if (finalTower > numberOfTowers)
        throw std::invalid_argument("ERROR: Final tower canntot be larger tha number of towers.");
    this->setTowers(numberOfTowers, numberOfRings);    
};

Board::~Board()
{
    for(TowerVector::iterator its = _towerVector.begin(); its != _towerVector.end(); its++)
    {
        delete *its;
    }    
}
void Board::setTowers(unsigned int numberOfTowers, unsigned int numberOfRings)
{
    for(int i = 0; i < numberOfTowers; i++)
    {
        _towerVector.push_back(new CTower(i+1));
    } 

    /* Fill only first tower*/
    for(int i = numberOfRings; i > 0; i--)
    {
        CRing* tmpRing = new CRing(i);
        _towerVector[0]->addRing(tmpRing);
    }
}

void Board::printBoard()
{
    int size = _towerVector.size();
    // std::cout<<height<<std::endl;
    for(int tVec = 0; tVec < size; tVec++)
    {
        for(int i = 0; i < _numberOfRings; i++)
            std::cout<<" ";
        std::cout<<"T"<<_towerVector[tVec]->_number<<":";
        for(int i = 0; i < _numberOfRings - 1; i++)
            std::cout<<" ";
    }
    std::cout<<std::endl<<std::endl;
    /*Row with picked ring*/
    for(int tVec = 0; tVec < size; tVec++)
    {
        if (isRingPicked() && tVec == _pointedTower )
                {
                    for(int i = 0; i < _numberOfRings - _pickedRing->getSize() + 1; i++)
                        std::cout<<" ";
                    for(int i = 0; i < _pickedRing->getSize(); i++)
                        std::cout<<(char)254u<<(char)254u;
                    for(int i = 0; i < _numberOfRings - _pickedRing->getSize() + 1; i++)
                        std::cout<<" ";
                }
                else
                {
                    for(int i = 0; i < _numberOfRings; i++)
                        std::cout<<" ";
                    if (tVec == _pointedTower)
                        std::cout<<(char)186u<<(char)186u;
                    else
                        std::cout<<"||";
                    
                    for(int i = 0; i < _numberOfRings; i++)
                        std::cout<<" ";
                }
    }
    std::cout<<std::endl;
    for(int ring = 0; ring < _numberOfRings; ring++)
    {    
        for(int tVec = 0; tVec < size; tVec++)
        {
            if (_towerVector[tVec]->_ringVector.size() >= _numberOfRings - ring)
            {
                int size = _towerVector[tVec]->_ringVector[_numberOfRings - ring - 1]->getSize();
                for(int i = 0; i < _numberOfRings - size + 1; i++)
                    std::cout<<" ";   
                for(int i = 0; i < size; i++)
                    std::cout<<(char)254u<<(char)254u;   
                for(int i = 0; i < _numberOfRings - size + 1; i++)
                    std::cout<<" "; 
            }
            else
            {
                for(int i = 0; i < _numberOfRings; i++)
                    std::cout<<" ";
                if (tVec == _pointedTower)
                    std::cout<<(char)186u<<(char)186u;
                else
                    std::cout<<"||";
                
                for(int i = 0; i < _numberOfRings; i++)
                    std::cout<<" ";
            }        
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Counter:"<<_movesCounter<<std::endl;
    // std::cout<<"Pointed tower:"<<_pointedTower + 1<<std::endl;
}

void Board::movePointerToRight()
{
    if (_pointedTower < _towerVector.size() - 1)
        _pointedTower++;
}

void Board::movePointerToLeft()
{
    if (_pointedTower > 0)
        _pointedTower--;
}

MessageCode Board::pickRing()
{
    MessageCode returnCode;
    if (_pickedRing != nullptr)
        return MessageCode::NO_MESSAGE;

    CTower* _tmpTower = _towerVector[_pointedTower]; 
    _pickedRing = _tmpTower->popRing(returnCode);
    return returnCode;
}

MessageCode Board::putRing()
{
    MessageCode returnCode;

    if (_pickedRing == nullptr)
        return MessageCode::NO_MESSAGE;

    CTower* tmpTower = _towerVector[_pointedTower]; 
    tmpTower->addRing(_pickedRing, returnCode);
    if (returnCode == MessageCode::NO_MESSAGE)
    {
        _pickedRing = nullptr;
        _movesCounter++;
    }
    
    return returnCode;
}
bool Board::hasAllRings(unsigned _tower)
{
    return (_towerVector[_tower]->_ringVector.size() == _numberOfRings);
}
bool Board::isGameOver()
{
    bool allRingsMovedToFinalTower = false;
    if (isFirstTowerEmpty())
    {
        if (hasAllRings(_finalTower - 1))
            allRingsMovedToFinalTower = true;
    }
    return allRingsMovedToFinalTower;
}