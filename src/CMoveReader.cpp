#include "CMoveReader.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h> 

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

MoveReader::MoveReader(Board *board):_board(board)
{
    //
}
// ~MoveReader();
void MoveReader::read()
{
    system("cls");
    _board->printBoard();
    while(decodeButton(getch()))
    {   
        system("cls");
        _board->printBoard();
        // printInterface();
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
void MoveReader::pickRing()
{
    try
    {
        _board->pickRing();
    }
    catch(const EmptyTowerException& e)
    {
        std::wcerr << e.what() << '\n';
    }
}
void MoveReader::putRing()
{
    try
    {
        _board->putRing();
    }
    catch(const GreaterRingException& e)
    {
        std::wcerr << e.what() << '\n';
    }
}

void MoveReader::printInterface()
{
    std::cout<<"###############################################"<<std::endl;
    std::cout<<warning<<std::endl;
    std::cout<<"###############################################"<<std::endl;
}

bool MoveReader::decodeButton(int button)
{
    warning = "";
    switch(button) {
        case KEY_UP:
            pickRing();
            break;
        case KEY_DOWN:
            putRing();
            break;
        case KEY_LEFT:
            movePointerToLeft();
            break;
        case KEY_RIGHT:
            movePointerToRight();
            break;
        case KEY_ESC:
            return false;
            break;
        default:
            std::cout << std::endl << "null" << std::endl;  // not arrow
            break;
    }
    return true;
}