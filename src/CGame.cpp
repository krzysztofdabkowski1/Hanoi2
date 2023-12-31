#include "CGame.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h> 

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_F2 60

Game::Game(Board *board, IAlgorithmResolver* resolver):
_board(board),
_resolver(resolver)
{
    //
}
void Game::run()
{
    system("cls");
    printHelpInfo();
    while(decodeButton(getch()))
    {   
        system("cls");
        _board->printBoard();
        printInterface();
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
    MessageCode retCode = _board->pickRing();
    if (retCode == MessageCode::EMPTY_TOWER)
        warning = "This tower is empty";
}
void Game::putRing()
{
    MessageCode retCode = _board->putRing();
    if (retCode == MessageCode::TOO_LARGE)
        warning = "This ring too large";
}
void Game::printInterface()
{
    std::cout<<"###############################################"<<std::endl;
    std::cout<<warning<<std::endl;
    std::cout<<"###############################################"<<std::endl;
    std::cout<<"###### ESC - quit the game, F2 - tip ##########"<<std::endl;
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
        case KEY_F2:
            _resolver->MakeNextStep(*_board);
            break;
        default:
            // std::cout << std::endl << button << std::endl;  // not arrow
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