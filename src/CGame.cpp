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
    printHelpInfo();

    // _board->printBoard();
    while(decodeButton(getch()))
    {   
        system("cls");
        _board->printBoard();
        if(gameOver())
            break;
    }
    printGameOverBanner();
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
            //std::cout << std::endl << "null" << std::endl;  // not arrow
            break;
    }
    return true;
}

bool Game::gameOver()
{
    return _board->isGameOver();
}

void Game::printGameOverBanner()
{
    std::cout<<"###############################################"<<std::endl;
    std::cout<<"You have completed the game. Your result is: "<<_board->getMoveCounter()<<std::endl;
    std::cout<<"###############################################"<<std::endl;    
}

void Game::printHelpInfo()
{
    std::cout<<"################################################"<<std::endl;
    std::cout<<"##  T  O  W  E  R     O  F     H  A  N  O  I  ##"<<std::endl; 
    std::cout<<"################################################"<<std::endl;    
    std::cout<<"################################################"<<std::endl; 
    std::cout<<std::endl;
    std::cout<<"Object of the game is to move all the disks over"<<std::endl;
    std::cout<<"to Tower "<<_board->getFinalTower()<<" by using arrow keys. But you cannot "<<std::endl;
    std::cout<<"place a larger disk onto a smaller disk.    "<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Press ESC key to quit the game."<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Press any other key to start the game..."<<std::endl;
}