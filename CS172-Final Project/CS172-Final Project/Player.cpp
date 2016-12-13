//  Player.cpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#include "Player.hpp"
#include <iostream>
using namespace std;

//defines void function in Player class to create a blank game board
void Player::createBoard(int array[5][5])
{
    //uses for loops to create a blank board
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
            array[x][y] = empty;
    }
}




