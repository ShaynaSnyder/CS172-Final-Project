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
    for (int rows = 0; rows <= 4; rows++)
    {
        for (int columns = 0; columns <= 4; columns++)
            array[rows][columns] = empty;
    }
}




