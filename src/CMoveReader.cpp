#include "CMoveReader.h"
#include <iostream>

MoveReader::MoveReader(Board *board):_board(board)
{
    //
}
// ~MoveReader();
void MoveReader::read()
{
    while(true)
    {   
        char input;
        std::cin>>input;
        std::cout<<input;
        _board->printBoard();
    }
}

void MoveReader::movePointerToRight()
{
    _board->movePointerToRight();
}
void MoveReader::movePointerToLeft()
{
    _board->movePointerToLeft();
}
void MoveReader::grabRing()
{
    //
}
void MoveReader::releaseRing()
{
    //
}