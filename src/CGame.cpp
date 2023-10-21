#include "CGame.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h> 

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

Game::Game(Board *board):_board(board)
{
    //
}
void Game::run()
{
    system("cls");
    _board->printBoard();
    while(decodeButton(getch()))
    {   
        if(gameOver())
            break;
        system("cls");
        _board->printBoard();
        // printInterface();
    }
}

void Game::movePointerToRight()
{
    _board->movePointerToRight();
}
void Game::movePointerToLeft()
{
    _board->movePointerToLeft();
}
void Game::pickRing()
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
void Game::putRing()
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

void Game::printInterface()
{
    std::cout<<"###############################################"<<std::endl;
    std::cout<<warning<<std::endl;
    std::cout<<"###############################################"<<std::endl;
}

bool Game::decodeButton(int button)
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

bool Game::gameOver()
{
    return false;
}