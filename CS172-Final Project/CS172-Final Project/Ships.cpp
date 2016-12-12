//
//  Ships.cpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1115/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//
#include "Ships.hpp"
#include <string>

Ships::Ships()
{
    name = "";
}
string Ships::getName(int shipN)
{
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
    name = shipNames[shipN];
    return name;
}
void Ships::hit(int refBoard[5][5], int x, int y)
{
    //if(refBoard[x][y]==hit)
        
}

void Ships::miss()
{
    
}

void Ships::sunkenShips(string name)
{
    // if (space == 'H')
    // cout << name << " has been destroyed"
    
}
