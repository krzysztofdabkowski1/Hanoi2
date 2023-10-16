#include "CBoard.h"
#include <iostream>
#include "windows.h" 
#include <math.h> 

Board::Board(unsigned int numberOfTowers, unsigned int numberOfRings, IAlgorithmResolver* resolver):
_resolver(resolver),
_numberOfRings(numberOfRings),
_pointedTower(0),
_pickedRing(nullptr)
{
    this->setTowers(numberOfTowers, numberOfRings);
    // try
    // {
    //     auto firstTower = _towerVector[0];
    //     auto secondTower = _towerVector[1];//(++_towerSet.begin());
    //     auto thirdTower = _towerVector[2];//(++(++_towerSet.begin()));
    //     CRing * tmpRing = firstTower->popRing();
    //     secondTower->addRing(tmpRing);
    //     tmpRing = firstTower->popRing();
    //     thirdTower->addRing(tmpRing);
    //     printBoard();
    //     tmpRing = thirdTower->popRing();
    //     printBoard();
    //     secondTower->addRing(tmpRing);
    //     printBoard();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    //     this->~Board();
    // }
    
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
            std::cout<<".";
        std::cout<<"T"<<_towerVector[tVec]->_number<<":";
        for(int i = 0; i < _numberOfRings; i++)
            std::cout<<".";
        //std::cout<<std::endl;
        // for(int rVec = _towerVector[tVec]->_ringVector.size() - 1; rVec >=0; rVec--)
        // {
        //     for (int i = 0; i < _towerVector[tVec]->_ringVector[rVec]->getSize(); i++)
        //         std::cout<<(char)254u;
        //     std::cout<<std::endl;
        // }
        //std::cout<<std::endl;
    }
    // std::cout<<"##############################"<<std::endl;
    std::cout<<std::endl;
    for(int ring = 0; ring < _numberOfRings; ring++)
    {    
        for(int tVec = 0; tVec < size; tVec++)
        {
            if (_towerVector[tVec]->_ringVector.size() >= _numberOfRings - ring)
            {
                for(int i = 0; i < _numberOfRings - floor(ring/2); i++)
                    std::cout<<".";   
                std::cout<<".";
                for(int i = 0; i < _towerVector[tVec]->_ringVector[_numberOfRings - ring - 1]->getSize(); i++)
                    std::cout<<(char)254u;   
                std::cout<<".";
                for(int i = 0; i < _numberOfRings - floor(ring/2); i++)
                    std::cout<<"."; 
            }
            else
            {
                for(int i = 0; i < _numberOfRings; i++)
                    std::cout<<".";
                //std::cout<<std::endl;
                std::cout<<"...";
                // for(int rVec = _towerVector[tVec]->_ringVector.size() - 1; rVec >=0; rVec--)
                // {
                //     for (int i = 0; i < _towerVector[tVec]->_ringVector[rVec]->getSize(); i++)
                //         std::cout<<(char)254u;
                //     std::cout<<std::endl;
                // }
                //std::cout<<std::endl;
                for(int i = 0; i < _numberOfRings; i++)
                    std::cout<<".";
            }
            
        }
        std::cout<<std::endl;
    }

    std::cout<<"Pointed tower:"<<_pointedTower + 1<<std::endl;
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

void Board::pickRing()
{
    if (_pickedRing != nullptr)
        return;

    CTower* _tmpTower = _towerVector[_pointedTower]; 
    _pickedRing = _tmpTower->popRing();
}

void Board::putRing()
{
    if (_pickedRing == nullptr)
        return;

    CTower* _tmpTower = _towerVector[_pointedTower]; 
    try
    {
        _tmpTower->addRing(_pickedRing);
        _pickedRing = nullptr;
    }
    catch(const GreaterRingException& e)
    {
        throw GreaterRingException();
    }
    
}
// void Board::printBoard()
// {
//     std::cout<<"##############################"<<std::endl;
//     for(TowerSet::iterator its = _towerSet.begin(); its != _towerSet.end(); its++)
//     {
//         std::cout<<"T"<<(*its)->_number<<": "<<std::endl;
//         for(RingSet::iterator itr = (*its)->_ringSet.begin(); itr != (*its)->_ringSet.end(); itr++)
//         {
//             std::cout<<(*itr)->getSize();
//         }
//         std::cout<<std::endl;
//     }
//     std::cout<<"##############################"<<std::endl;
// }