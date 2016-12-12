//
//  Player.cpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1211/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
using namespace std;

void Player::setPlayerNumber(const int& num)
{
    this->num = num;
}

void Player::getPlayerNumber() const
{
    if (num == 1)
    {
        cout << "You will guess first." << endl;
    }
    else
    {
        cout << "You will guess second." << endl;
    }
    
}

void Player::createBoard(int array[5][5])
{
    // create a blank board
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
            array[x][y] = empty;
    }
}
