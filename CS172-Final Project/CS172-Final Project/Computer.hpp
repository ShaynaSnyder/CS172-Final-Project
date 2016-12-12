//
//  Computer.hpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1211/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include "Player.hpp"

using namespace std;
class Computer: public Player
{
public:
    Computer();
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
};

#endif /* Computer_hpp */
