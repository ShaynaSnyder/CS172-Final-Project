//
//  Human.hpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1211/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//


#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
class Human: public Player
{
public:
    
    Human(string);
    string getName(string);
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
    void makeGuessC(int array[5][5]);
    
    
};


#endif /* Human_hpp */
