//  Player.hpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//creates Player class
class Player
{
public:
    void createBoard(int array[5][5]);
    const int empty    = 0;  // empty
    const int occupied = 1;  // contains a ship
    const int missed   = 2;  // missed
    const int hit      = 3;  // hit
    int xhuman[5], yhuman[5], xcomputer[5], ycomputer[5], humanBoard[5][5], compBoard[5][5], repeat=0, x, y;
    char letterlocation[5];
    
    
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
private:
    int num;
};

#endif /* Player_hpp */
