#include "CBoard.h"
#include <iostream>

Board::Board(unsigned int numberOfTowers, unsigned int numberOfRings, IAlgorithmResolver* resolver):_resolver(resolver)
{
    this->setTowers(numberOfTowers, numberOfRings);
    auto firstTower = getNthTower(0);
    auto secondTower = getNthTower(1);//(++_towerSet.begin());
    auto thirdTower = getNthTower(2);//(++(++_towerSet.begin()));
    CRing * tmpRing = firstTower->popRing();
    secondTower->addRing(tmpRing);
    tmpRing = firstTower->popRing();
    thirdTower->addRing(tmpRing);
     printBoard();
    tmpRing = thirdTower->popRing();
    printBoard();
    secondTower->addRing(tmpRing);
    printBoard();
};

void Board::setTowers(unsigned int numberOfTowers, unsigned int numberOfRings)
{
    for(int i = 0; i < numberOfTowers; i++)
    {
        CTower* tmpTower = new CTower(i+1);
        _towerSet.insert(tmpTower);
    } 

    /* Fill only first tower*/
    auto firstTower = _towerSet.begin();
    for(int i = numberOfRings; i > 0; i--)
    {
        CRing* tmpRing = new CRing(i);
        //std::cout<<(*firstTower)->_number;
        (*firstTower)->addRing(tmpRing);
    }
}

void Board::printBoard()
{
    int height = _towerSet.size();
    std::cout<<height<<std::endl;
    std::cout<<"##############################"<<std::endl;
    for(TowerSet::iterator its = _towerSet.begin(); its != _towerSet.end(); its++)
    {
        std::cout<<"T"<<(*its)->_number<<": "<<std::endl;
        for(RingSet::iterator itr = (*its)->_ringSet.begin(); itr != (*its)->_ringSet.end(); itr++)
        {
            std::cout<<(*itr)->getSize();
        }
        std::cout<<std::endl;
    }
    std::cout<<"##############################"<<std::endl;
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

CTower* Board::getNthTower(const int n)
{   
    if (n > _towerSet.size())
        return nullptr;

    int counter = 0;
    TowerSet::iterator its = _towerSet.begin();
    while(counter < n)
    {
        its++;
        counter++;
    }
    return *its;
}