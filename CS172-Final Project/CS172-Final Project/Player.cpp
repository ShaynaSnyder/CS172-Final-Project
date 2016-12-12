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

void Player::createBoard(int array[5][5])
{
    // create a blank board
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
            array[x][y] = empty;
    }
}


